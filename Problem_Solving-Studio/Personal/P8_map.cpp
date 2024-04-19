#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, d, m;
    cin >> n >> d >> m;
    
    map<int, int> tasksForEachDay;
    for (int i = 0; i < m; i++) {
        int startDate;
        cin >> startDate;
        tasksForEachDay[startDate]++;
    }
    
    bool completed = false;
    int bulldozer = 1;
    
    while (!completed) {
        
        int remainTask = 0;
        completed = true;
        
        for (auto& day : tasksForEachDay) {
            if (((day.second + remainTask) / static_cast<double>(d + 1)) > bulldozer) {
                bulldozer++;
                completed = false;
                break;
            }
            remainTask = (day.second + remainTask) - bulldozer;
            remainTask = max(0, remainTask);
        }
        
    }
    
    cout << bulldozer << endl;
    return 0;
}
