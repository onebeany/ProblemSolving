#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

bool compare(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
    return a.first > b.first;
}

int findDifficulty(vector<vector<int>>& cells, vector<vector<bool>>& visit, pair<int, int>& curr_cell);

void checkAndUpdate(int x, int y, int curr_value,
                    vector<vector<int>>& cells, vector<vector<bool>>& visit,
                    queue<pair<int, int>>& q, int& min_altitude);



int main(){
    
    int n; cin >> n;
    vector<vector<int>> cells(n, vector<int>(n));
    vector<pair<int, pair<int, int>>> sorted_cells;
    vector<vector<bool>> visit(n, vector<bool>(n ,false));
    
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            int value; cin >> value;
            cells[i][j] = value;
            sorted_cells.push_back({value, {i, j}});
        }
    }
    
    sort(sorted_cells.begin(), sorted_cells.end(), compare);
    
    int global_max = 0;
    
    for(int i = 0 ; i < n ; i++){
        
        int x = sorted_cells[i].second.first, y = sorted_cells[i].second.second;
        if(visit[x][y] == 1) continue;
        
        pair<int, int> curr_cell = {x, y};
        int local_max = findDifficulty(cells, visit, curr_cell);
        
        global_max = max(global_max, local_max);
        
    }
    
    cout << global_max;
    
}

int findDifficulty(vector<vector<int>>& cells, vector<vector<bool>>& visit, pair<int, int>& curr_cell){
    
    queue<pair<int, int>> q;
    q.push(curr_cell);
    int x = curr_cell.first, y = curr_cell.second;
    visit[x][y] = true;
    
    int start_altitute = cells[x][y];
    int min_altitude = pow(10, 8) + 1;
    
    while(!q.empty()){
        
        curr_cell = q.front();
        q.pop();
        
        x = curr_cell.first; y = curr_cell.second;
        int curr_value = cells[x][y];
        
        // 12시부터 시계 방향으로 총 네 개의 방향 조회.
        checkAndUpdate(x, y-1, curr_value, cells, visit, q, min_altitude);  // Up
        checkAndUpdate(x+1, y, curr_value, cells, visit, q, min_altitude);  // Right
        checkAndUpdate(x, y+1, curr_value, cells, visit, q, min_altitude);  // Down
        checkAndUpdate(x-1, y, curr_value, cells, visit, q, min_altitude);  // Left
        
        /*
        if(y-1 >= 0 && !(visit[x][y-1]) && cells[x][y] > cells[x][y-1]){
            q.push({x, y-1});
            visit[x][y-1] = true;
            if(cells[x][y-1] < min_altitute) min_altitute = cells[x][y-1];
        }
        if(x+1 < cells.size() && !(visit[x+1][y]) && cells[x][y] > cells[x+1][y]){
            q.push({x+1, y});
            visit[x+1][y] = true;
            if(cells[x+1][y] < min_altitute) min_altitute = cells[x+1][y];
        }
        if(y+1 < cells.size() && !(visit[x][y+1]) && cells[x][y] > cells[x][y+1]){
            q.push({x, y+1});
            visit[x][y+1] = true;
            if(cells[x][y+1] < min_altitute) min_altitute = cells[x][y+1];
        }
        if(x-1 >= 0 && !(visit[x-1][y]) && cells[x][y] > cells[x-1][y]){
            q.push({x-1, y});
            visit[x-1][y] = true;
            if(cells[x-1][y] < min_altitute) min_altitute = cells[x-1][y];
        }
         */
        
    }
    
    return start_altitute - min_altitude;
    
}

void checkAndUpdate(int x, int y, int curr_value, vector<vector<int>>& cells, vector<vector<bool>>& visit,
                    queue<pair<int, int>>& q, int& min_altitude) {
    if (x >= 0 && x < cells.size() && y >= 0 && y < cells[0].size() &&
        !visit[x][y] && curr_value > cells[x][y]) {
        q.push({x, y});
        visit[x][y] = true;
        min_altitude = min(min_altitude, cells[x][y]);
    }
}
