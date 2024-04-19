#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    
    int n, t;
    cin >> n >> t;
    
    int p[n];
    int v[n];
    long long afterTPos[n];
    
    for(int i = 0; i < n ; i++){
        cin >> p[i] >> v[i];
    }
    
    sort(p, p+n);
    
    for(int i = 0 ; i < n ; i++){
        afterTPos[i] = p[i] + (long long) v[i] * t;
    }
    
    int numGroup = 1;
    
    for(int i = 1 ; i < n ; i++){
        if(afterTPos[i-1] >= afterTPos[i]) continue;
        else numGroup++;
    }
    
    cout << numGroup;
    
}

/*
 
1. Time Complexity

   Sorting the initial postion of people: O(nlogn)
 
2. <Error Case>
 
 1) Overflow
    
    Since the max of both of t and v is 1,000,000,000, t_max * v_max can result in overflow: (1,000,000,000)^2.
    -> long long 사용하여 overflow 방지.
 
 2)
 
 */
