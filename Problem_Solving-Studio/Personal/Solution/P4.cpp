//
//  P4.cpp
//  Personal
//
//  Created by Bean's Macbook Pro on 2023/10/06.
//

#include <iostream>
#include <stdio.h>
#include <set>
#include <algorithm>

using namespace std;

struct cmp{
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
        return a.first < b.first;
    }
};

void insertToF(set<pair<int, int>, cmp>& f, pair<int, int>& element);
void constructSF(set<pair<int, int>, cmp>& f);
int getResult(set<pair<int, int>, cmp>& f, int p, int q);

int main(){
    
    set<pair<int,int>, cmp> f;
    pair<int, int> e; // element of Step function.
    
    // Define the step function f,
    
    int k_f; 
    cin >> k_f;
    
    for(int i = 0 ; i < k_f ; i++){
        cin >> e.first >> e.second;
        f.insert(e);
    }
    
    // Megrge the elements of step function g into f.
    
    int k_g; cin >> k_g;
    
    for(int i = 0 ; i < k_g ; i++){
        cin >> e.first >> e.second;
        insertToF(f, e);
    }
    
    constructSF(f);
    
    // cout << "--------------\n";
    // for(auto it : f){
    //     cout << it.first << " " << it.second << endl;
    // }
    // cout << "--------------\n";


    int p, q;
    cin >> p >> q;
    
    int result = getResult(f, p, q);
    
    cout << result;
    
    return 0;
}

void insertToF(set<pair<int, int>, cmp>& f, pair<int, int>& e){
    
    auto it = f.lower_bound(e);
    
    if(it != f.end() && it->first == e.first){
        if(it->second < e.second){
            f.erase(it);  // Remove the old pair
            f.insert(e);
        }
    }
    else f.insert(e);
    
}

void constructSF(set<pair<int, int>, cmp>& f){
    
    auto it = f.begin();
    
    while(it != f.end()){
        
        auto curr_element = *it;
        auto next_it = next(it);
        
        // 만약 현재 범위의 함수값이 다음 범위의 함수값보다 크거나 같다면, 다음 범위를 대표하는 element는 제거.
        if(next_it != f.end() && curr_element.second >= next_it->second){
            f.erase(next_it);
        }
        else it++;
        
    }
    
}

int getResult(set<pair<int, int>, cmp>& f, int p, int q){
    
    if(q < f.begin()->first) return 0;
    if(p >= (--f.end())->first){
        return ( (q-p+1) * (--f.end())->second ) % 10007;
    }

    int result = 0;
    
    int currValue = p;
    if(currValue < f.begin()->first){ // f(p) == 0 -> 무의미
        currValue = f.begin()->first;
    }

    auto currStep = prev(f.upper_bound(pair<int, int>(currValue, 0)));

    //cout << "StaringPoint: " << currStep->first << endl;

    while(currValue <= q){
        //cout << "currValue: " << currValue << endl;
        if(next(currStep) == f.end()){
            int gap = q - currValue + 1;
            result += gap * currStep->second;
            result %= 10007;
            break;
        }

        int gap = min(q, next(currStep)->first) - currValue;
        result += gap * currStep->second;
        result %= 10007;
        
        if(q < next(currStep)->first) break;
        currStep++;
        currValue = currStep->first;

    }
    
        return result;
}

