#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> rods(4);

// Disk가 현재 위치한 rod 찾기
int findRod(int N);
int findVia(int start, int to);
int hanoi(int N, int start, int to);

int main(){
    
    int N, to; cin >> N >> to;
    
    for(int i = 1 ; i < 4 ; i++){
        int j; cin >> j;
        if(j==0) {int temp; cin >> temp;}
        for(int k = 0 ; k < j ; k++){
            int disk; cin >> disk; 
            rods[i].push_back(disk);
        }
    }
    
    // 가장 큰 disk부터 시작
    int start = findRod(N);
    int result;
    
    if((int)rods[to].size() == N) result = 0;
    else result = hanoi(N, start, to);
    
    cout << result;
    
    return 0;
}

int findRod(int N){
    
    int index = -1;
    
    for(int i = 1 ; i < 4 ; i++){
        if(find(rods[i].begin(), rods[i].end(), N) != rods[i].end()){
            index = i;
            break;
        }
    }
    
    return index;
}

int findVia(int start, int to){
    
    int via = -1;
    
    for(int i = 1 ; i < 4 ; i++)
        if( i != start && i != to) via = i;
    
    return via;
}

int move(int N, int start, int to){
    
    if(start == to) return 0;
    
    rods[start].erase(find(rods[start].begin(), rods[start].end(), N));
    rods[to].push_back(N);
    
    return 1;
}

int hanoi(int N, int start, int to){
    
    if(N==1) return move(N, start, to);
    else if(start == to){
        return hanoi(N-1, findRod(N-1), to);
    }
    else{
        return hanoi(N-1, findRod(N-1), findVia(start, to)) + move(N, start, to) + hanoi(N-1, findVia(start, to), to);
    }
}
