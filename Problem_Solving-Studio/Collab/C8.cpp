#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main () {
   
    int n;
    cin >> n;
    
    pair<int, int> buildings[n];
    bool isPaired[n];
    for(int i = 0 ; i < n ; i++){
        cin >> buildings[i].first >> buildings[i].second;
        isPaired[i] = false;
    }
    sort(buildings, buildings+n);
    
    int numPair = 0;
    for(int i = 0 ; i < n ; i++){
        
        if(isPaired[i]) continue;

        for(int j = i + 1 ; j < n ; j++){
            if(buildings[j].first - buildings[i].first > 5) break;
            if(isPaired[j]) continue;
            if((pow(buildings[i].first - buildings[j].first, 2) + pow(buildings[i].second - buildings[j].second, 2)) <= 25){
                isPaired[i] = true;
                isPaired[j] = true;
                numPair++;
                break;
            }
        }
    }
    
    cout << numPair;
}
