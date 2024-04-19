#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct rangeRepresent{
    long long startPoint;
    long long c;
};

bool compare(rangeRepresent &a, rangeRepresent &b){
    return a.startPoint < b.startPoint;
}

int main() {

    int k_f; // number of sets dividing the range, for step function f.
    cin >> k_f;
    rangeRepresent f[k_f];
    for(int i = 0 ; i < k_f ; i++){
        cin >> f[i].startPoint >> f[i].c;
    }
    sort(f, f + k_f, compare);

    int k_g;
    cin >> k_g;
    rangeRepresent g[k_g];
    for(int i = 0 ; i < k_g ; i++){
        cin >> g[i].startPoint >> g[i].c;
    }
    sort(g, g + k_g, compare);

    int p, q;
    cin >> p >> q;

    for(int i = p ; i <= q ; i++){

        


    }






}