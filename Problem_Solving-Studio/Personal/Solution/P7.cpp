#include <iostream>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

struct Range{
    int start;
    int end;
};

bool compare(const Range& a, const Range& b){
    if(a.start == b.start) return a.end > b.end;
    return a.start < b.start;
}

int main(){
    
    int n, d;
    cin >> n >> d;
    
    Range wellRange[n];
    
    for(int i = 0 ; i < n ; i++){
        int x, y;
        cin >> x >> y;
        wellRange[i].start = x - sqrt(d*d - y*y);
        wellRange[i].end = x + sqrt(d*d - y*y);
    }
    
    sort(wellRange, wellRange + n, compare);
    
    Range currWellRange = wellRange[0];
    int wells = 1;
    
    for(int i = 1 ; i < n ; i++){
        if(wellRange[i].start > currWellRange.end){
            currWellRange = wellRange[i];
            wells++;
        }
        else{
            currWellRange.end = min(currWellRange.end, wellRange[i].end);
        }
    }
    cout << wells;
}
