#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxWeight=0;

void searchCliques(vector<int> C, vector<int> P, vector<int> X, int * weight, vector<int> * link, int n) {
    int curWeight = 0;
    for(int x : C) {
        curWeight += weight[x];
    }
    maxWeight = max(maxWeight, curWeight);
    if(P.empty()) return;

    for(int p : P) {
        if(find(X.begin(), X.end(), p) != X.end()) continue;
        
        bool check = true;
        for(int c : C) {
            if (find(link[p].begin(), link[p].end(), c) == link[p].end()) {
                check = false;
                break;
            }
        }
        if(check) {
            vector<int> newC, newP;
            newC = C;
            newC.push_back(p);
            for(int x : link[p]) {
                newP.push_back(x);
            }
            searchCliques(newC, newP, X, weight, link, n);
        }
    }
}

void findMaxWeight(int * weight, vector<int> * link, int n) {
    vector<int> X;
    for(int i=0; i<n; i++) {
        vector<int> C, P;
        C.push_back(i);
        for(int x : link[i]) P.push_back(x);
        searchCliques(C, P, X, weight, link, n);
        X.push_back(i);
    }
}

int main() {
    int n, b;
    cin >> n >> b;
    
    int weight[n];
    for(int i=0; i<n; i++) {
        cin >> weight[i];
    }

    vector<int> link[n];
    for(int i=0; i<b; i++) {
        int e1, e2;
        cin >> e1 >> e2;
        e1--;
        e2--;
        link[e1].push_back(e2);
        link[e2].push_back(e1);
    }
    
    findMaxWeight(weight, link, n);

    cout << maxWeight;
}
