//
//  P4.cpp
//  Personal
//
//  Created by Bean's Macbook Pro on 2023/10/06.
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int findInsertPosition(const vector<pair<int, int>>& f, const pair<int, int>& e_g);

void printStepFunction(const vector<pair<int,int>>& f);


int main(){
    
    // Define the step function f,
    
    int k_f; cin >> k_f;
    
    vector<pair<int,int>> f(k_f);
    for(int i = 0 ; i < k_f ; i++){
        cin >> f[i].first >> f[i].second;
    }
    sort(f.begin(), f.end());
    
    printStepFunction(f);
    
    // Get each pair of step function g, and merge them to the f.
    
    int k_g; cin >> k_g;
    
    pair<int, int> e_g; // Element of g function
    int position; // Position to insert into f.
    
    for(int i = 0 ; i < k_g ; i++){
        cin >> e_g.first >> e_g.second;
        position = findInsertPosition(f, e_g);
        // printf("(%d, %d) should be located before f[%d]: (%d, %d)\n", e_g.first, e_g.second, position, f[position].first, f[position].second);
    }
    
    
    
    return 0;
}

int findInsertPosition(const vector<pair<int, int>>& f, const pair<int, int>& e_g){
    
    int low = 0, high = (int)f.size() - 1, mid;
    
    while(low <= high){
        
        mid = low + (high - low) / 2;
        
        if(f[mid].first == e_g.first) return mid;
        else if (f[mid].first < e_g.first) low = mid + 1;
        else high = mid - 1;
        
    }
    
    return low;
}

void printStepFunction(const vector<pair<int,int>>& f){
    printf("Step function f: {");
    for(auto element: f)
        printf(" (%d, %d),", element.first, element.second);
    printf("}\n\n");
}
