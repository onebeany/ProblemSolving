#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Applicant{
    int x, y;
    bool isGrouped = false;
    
    bool operator<(const Applicant& other) const {
        if (x == other.x) return y < other.y;
        return x < other.x;
    }
};


bool canGrouped(const Applicant& a, const Applicant& b){
    return ((a.x > b.x) && (a.y < b.y)) || ((a.x < b.x) && (a.y > b.y));
}

int main() {
    
    int n;
    cin >> n;
    
    vector<Applicant> applicants(n);
    
    for(int i = 0; i < n; i++)
        cin >> applicants[i].x >> applicants[i].y;
    
    sort(applicants.begin(), applicants.end());
    
    int numOfGroups = 0;
    
    for(int i = 0 ; i < n ; i++){
        
        bool makeNewGroup = false;
        
        for(int j = i+1 ; j < n ; j++){
            
            if(canGrouped(applicants[i], applicants[j])){
                
                // 두 applicant 모두 그룹에 속해 있지 않은 상태 (false false)
                if(!(applicants[i].isGrouped || applicants[j].isGrouped)){
                    makeNewGroup = true;
                    applicants[i].isGrouped = true;
                    applicants[j].isGrouped = true;
                }
                // 두 applicant가 이미 그룹에 속해있다면 -> 새로 그룹을 만들 필요가 없음 (true true)
                else if(applicants[i].isGrouped && applicants[j].isGrouped) makeNewGroup = false;
                else{
                    if(!applicants[i].isGrouped) applicants[i].isGrouped = true; // (false, true)
                    if(!applicants[j].isGrouped) applicants[j].isGrouped = true; // (true, false)
                }
            }
        }
        
        if(makeNewGroup || !applicants[i].isGrouped){
            if(!applicants[i].isGrouped) applicants[i].isGrouped = true;
            numOfGroups++;
        }
    }
    cout << numOfGroups;
    
    return 0;

}
