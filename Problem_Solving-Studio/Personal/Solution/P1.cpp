//
//  p1.cpp
//  PSS_personal
//
//  Created by Bean's Macbook Pro on 2023/09/12.
//

#include <iostream>
#include <stdio.h>
#include <set>

using namespace std;

struct Building{
    int num_people;
    double location;
    
    // locate the building with smaller location right before the next big one.
    bool operator < (const Building &var) const{
        return location < var.location;
    }
};

int main(int argc, const char * argv[]) {
    
    int n, k; cin >> n >> k; // n: number of buildings, k: walding distance -> each way: 2k
    
    set<Building> buildings;
    
    int people; // people <-> num_people
    double point; // point <-> location
    
    for(int i = 0 ; i < n ; i++){
        cin >> people >> point; buildings.insert({people, point});
    }

    int wr = 2*k; // range of walking distance.
    int max = 0; // the maximum people in buildings in walking distanece from the hospital.
    int rangeSum = 0; // the sum of range
    
    /*
     - current building for summing up people in buildings
       from current_point of this building to current_point + 2k
     - Actual hospital point: current_point of this building (curr + k)
     */
    
    auto curr = buildings.begin(); // current building
    auto iter = buildings.begin();
    
    while(iter != buildings.end()){
        
        if(iter->location > curr->location + wr ){
            if(rangeSum > max) max = rangeSum;
            rangeSum -= curr->num_people; curr++;
        }
        else{
            rangeSum += iter->num_people;
            iter++;
        }
        
        if(iter->location == buildings.rbegin()->location)
            if(rangeSum > max) max = rangeSum;
        
    }
    
    cout << max;
        
    return 0;
}
