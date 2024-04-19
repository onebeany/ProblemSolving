#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b){
    if(a.first == b.first) return a.second > b.second;
    return a.first > b.first;
}

double distanceToWell(int wellX, int villageX, int villageY) {
    return sqrt(pow(villageX - wellX, 2) + pow(villageY, 2));
}

int main(){
    
    int n, d;
    cin >> n >> d;
    
    pair<int, int> villages[n];
    int x, y;
    
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        villages[i] = make_pair(x, y);
    }
    
    sort(villages, villages + n, compare);
    
    int wells = 1;
    int currWellX = villages[0].first;
    int currWellY = 0; // Well is always on the border, so y-coordinate is 0
    
    for(int i = 1; i < n; i++){
        x = villages[i].first;
        y = villages[i].second;
        
        if(distanceToWell(currWellX, x, y) > d){
            // Recalculate the well position for this village
            currWellX = max(currWellX, x - int(floor(sqrt(d*d - y*y))));
            wells++;
        }
    }
    
    cout << wells << endl;
    return 0;
}



/*
#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b){
    if(a.first == b.first) return a.second > b.second;
    return a.first > b.first;
}

int main(){
    
    int n;
    double d;
    cin >> n >> d;
    
    pair<int, int> villages[n];
    int x, y;
    
    for(int i = 0 ; i < n ; i++){
        cin >> x >> y;
        villages[i] = make_pair(x, y);
    }
    
    sort(villages, villages + n, compare);
    
    int wells = 1;
    x = villages[0].first; y = villages[0].second;
    int currWellPoint = x - floor(sqrt(d*d - y*y));
    
    for(int i = 1 ; i < n ; i++){
        x = villages[i].first; y = villages[i].second;
        cout << "villages[" << i << "] | (" << x << ", " << y << "): ";
        double calD = sqrt(pow(x - currWellPoint, 2) + pow(y, 2));
        cout << calD << endl;
        if(calD > d){
            cout << "far!" << endl;
            currWellPoint = x - floor(sqrt(d*d - y*y));
            wells++;
        }
        else {
            cout << "within!" << endl;
        }
    }
    
    cout << wells;
}
*/
