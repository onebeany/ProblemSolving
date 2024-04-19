#include <iostream>
#include <algorithm>

using namespace std;

int main () {
    int n, d, m;
    cin >> n >> d >> m;
    
    int startDates[m];
    int latestDate = 0; // Latest Start Date
    for(int i = 0 ; i < m ; i++){
        cin >> startDates[i];
        if(startDates[i] > latestDate) latestDate = startDates[i];
    }
    
    int tasksForEachDay[latestDate+1];
    int lenTotalDays = (int) (sizeof(tasksForEachDay) / sizeof(int));
    for(int i = 1 ; i < lenTotalDays ; i++){
        tasksForEachDay[i] = 0;
    }
    
    for(int i = 0 ; i < m ; i++){
        tasksForEachDay[startDates[i]]++;
    }
        
    bool completed = false;
    int bulldozer = 1;
    while(!completed){
        
        int remainTask = 0;
        for(int i = 1 ; i < lenTotalDays ; i++){
        
            if(((tasksForEachDay[i] + remainTask) / (double) (d+1)) > bulldozer){
                bulldozer++;
                break;
            }
            remainTask = (tasksForEachDay[i] + remainTask) - bulldozer;
            if(remainTask < 0) remainTask = 0;
            if(i == lenTotalDays-1) completed = true;
        }
    }
    
    cout << bulldozer;
    
    return 0;
}
