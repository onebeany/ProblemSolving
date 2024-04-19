//
//  C2.cpp
//  Collab
//
//  Created by Bean's Macbook Pro on 2023/09/14.
//

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

vector<int> findMinimumFuel(int start, int N, vector<int> cities[], int fuelCost)
{
    vector<int> totalFuelCost(N, INF);  // 각 city로의 fuel cost를 저장할 리스트 초기화
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  // 우선순위 큐 선언

    totalFuelCost[start] = 0;  // 시작 city의 fuel cost는 0으로 설정
    pq.push({ 0, start });  // 우선순위 큐에 넣기

    while (!pq.empty())
    {
        int curr_fuel = pq.top().first; // 큐에서 꺼내 방문하고 있는 city의 totalFuelCost
        int curr_city = pq.top().second;  // city의 인덱스
        
        pq.pop();

        for (int i = 0; i < (int)cities[curr_city].size(); i++)
        {
            int next_city = cities[curr_city][i];  // 연결된 city 인덱스
            int next_fuel = curr_fuel + fuelCost;  // 연결된 city까지의 totalFuelCost
            
            if (next_fuel < totalFuelCost[next_city])  // 지금 계산한 것이 기존 totalFuelCost값보다 작다면
            {
                totalFuelCost[next_city] = next_fuel;  // fuel cost 업데이트
                pq.push({ next_fuel, next_city });  // 우선순위 큐에 넣기
            }
        }
    }

    return totalFuelCost;  // start city로부터 각 city까지의 최소 연료 소모량을 담은 벡터 리턴
}

int main()
{
    
    int p, q, r, N, M;
    cin >> p >> q >> r >> N >> M;
    
    vector<int> cities[N];  // 2차원 벡터로 도시 구성, 도시간 연결성 represented
    
    for (int i = 0; i < M; i++)
    {
        int from, to; // 출발 도시, 도착 도시
        cin >> from >> to;
        cities[from-1].push_back(to-1);
        cities[to-1].push_back(from-1);
    }
    
    vector<int> alphaFuel = findMinimumFuel(0, N, cities, p);
    vector<int> betaFuel = findMinimumFuel(1, N, cities, q);
    vector<int> coupledFuel = findMinimumFuel(N-1, N, cities, r);
    
    int min = alphaFuel[N-1] + betaFuel[N-1] + coupledFuel[N-1];
    
    for(int i = 0 ; i < N-1 ; i++){
        int sum = alphaFuel[i] + betaFuel[i] + coupledFuel[i];
        if(sum < min) min = sum;
    }
    
    cout << min;
    
    return 0;
}
