#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

// Print all case
int main(){
    
    int n, t;
    cin >> n >> t;
    vector<pair<int, int>> people;
    
    for(int i = 0; i < n ; i++){
        int p, v;
        cin >> p >> v;
        people.push_back(make_pair(p, v));
    }
    sort(people.begin(), people.end());
    
    for(int i = 0 ; i <= t; i++){
        cout << "t: " << i << " |\t";
        for(int j = 0 ; j < n ; j++){
            cout << people[j].first + people[j].second * i << " ";
        }
        cout << endl;
    }
    
    /*
    int currBiggestPos = afterTPosition[0];
    int numGroup = 1;
    
    for(int i = 1 ; i < n ; i++){
        if(currBiggestPos >= afterTPosition[i]) continue;
        else{
            currBiggestPos = afterTPosition[i];
            numGroup++;
        }
    }
    */
    
    //cout << numGroup;
    
}

/*

 #include <iostream>
 #include <algorithm>
 #include <vector>
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
     cout << endl;
     
     sort(people, people+n, compare);
     
     
     for(int i = 0 ; i < n ; i++){
         cout << people[i].first << " " << people[i].second << endl;
     }
     
     for(int i = 1 ; i < n ; i++){
         if((people[i-1].first == people[i].first) && (people[i-1].second < people[i].second)){
             people[i].second = people[i-1].second;
         }
     }
     
     for(int i = 0 ; i < n ; i++){
         cout << people[i].first << " " << people[i].second << endl;
     }
     
     
     for(int i = 0 ; i < n ; i++){
         afterTPos[i] = people[i].first + (long long) people[i].second * t;
     }
     
     for(int i = 0 ; i < n ; i++){
         cout << afterTPos[i] << " ";
     } cout << endl;
     
     
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
     
 }


*/

/*
 
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
     /*
     for(int i = 1 ; i < n ; i++){
         if((people[i-1].first == people[i].first) && (people[i-1].second < people[i].second)){
             people[i].second = people[i-1].second;
         }
     }
     */
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


 */
