#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b){
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

int main(){
    
    int n, t;
    cin >> n >> t;
    
    pair<int, int> people[n];
    long long afterTPos[n];
    
    for(int i = 0; i < n ; i++){
        cin >> people[i].first >> people[i].second;
    }

    sort(people, people+n, compare);

    for(int i = 0 ; i < n ; i++){
        afterTPos[i] = people[i].first + (long long) people[i].second * t;
    }
    
    int numGroup = 1;
    long long currVeryFront = afterTPos[0];
    
    for(int i = 1 ; i < n ; i++){
        if(afterTPos[i] >= currVeryFront) continue;
        else {
            currVeryFront = afterTPos[i];
            numGroup++;
        }
    }
    
    cout << numGroup;
    
    return 0;
}

