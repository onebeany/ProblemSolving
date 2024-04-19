#include <iostream>
#include <stdio.h>
#include <vector>
#include <climits>

#define INF INT_MAX;

using namespace std;

int weldAdjacentSegment(vector<int>& cableSegments, int n);

int main()
{
    int n;
    cin >> n;
    
    vector<int> cableSegements(n);
    
    for(int i = 0 ; i < n ; i++)
        cin >> cableSegements[i];
    
    cout << endl;
        
    cout << weldAdjacentSegment(cableSegements, n) << endl;
    
    return 0;
}

int weldAdjacentSegment(vector<int>& cableSegments, int n){

    // 각 segment의 길이 축적값 저장 위한 벡터 선언
    vector<int> accumSum(n, 0);
    
    // 어떤 segment부터 다른 segment까지의 minimum cost를 저장하기 위한 2차원 벡터 array 생성
    vector<vector<int>> minCostFromTo(n, vector<int>(n));

    for (int i = 0; i < n; i++){
        if(i==0) accumSum[i] = cableSegments[i] + 0;
        else accumSum[i] = cableSegments[i] + accumSum[i - 1];
        minCostFromTo[i][i] = 0; // welding에는 적어도 두 segment가 필요하기에, 한 개의 segment는 welding 시간 걸리지 않음.
    }
    
    // segment의 결합이 두 개 이상인 것부터 마지막 n까지의 경우 반복.
    for (int numOfSegments = 2; numOfSegments <= n; numOfSegments++) {

        for (int i = 0; i < n - numOfSegments + 1; i++) {
            
            // i번째 segment로부터 numOfSegments만큼 떨어진 segment의 위치 j
            // [i, j]이므로 뒤에 -1을 해준다. (i 포함이므로)
            int j = i + numOfSegments - 1;
            
            cout << "[numOfSegments]: " << numOfSegments << "\n[i, j] = [" << i+1 << ", " << j+1 << "]\n\n";
            
            // [i, j](두 segment 사이)의 accumSum 구하기
            int betweenSum;
            if(i==0) betweenSum = accumSum[j];
            else betweenSum = accumSum[j] - accumSum[i - 1];
            
            minCostFromTo[i][j] = INF; // 최솟값 비교를 위해 일단 무한값으로 초기화.
            
            // k는 [i, j] 사이에 가능한 파티션 segment 위치.
            for (int k = i; k < j; k++){
                // 기존에 저장되어 minCostFromTo[i][j] 값과
                // [i, k]의 sum, [k+1, j]의 sum, 그리고 [i, j]의 sum의 합을 비교하여 최솟값 업데이트
                minCostFromTo[i][j] = min(minCostFromTo[i][j], minCostFromTo[i][k] + minCostFromTo[k + 1][j] + betweenSum);
                printf("minCostFromTo[%d][%d] = min(minCostFromTo[%d][%d], minCostFromTo[%d][%d] + minCostFromTo[%d][%d] + accumSum[%d~%d])\n", i+1, j+1, i+1, j+1, i+1, k+1, k+2, j+1, i+1, j+1);
            }
            
            
            printf("\n\t");
            for(int i = 0 ; i < n ; i++)
                printf("%3d ", i+1);
            cout << "\n\n";
            
            for(int i = 0 ; i < n ; i++){
                printf("%2d\t", i+1);
                for(int j = 0 ; j < n ; j++)
                    printf("%3d ", minCostFromTo[i][j]);
                cout << endl;
            }
            cout << "\n------------------------------------------\n\n";
        }
    }
    return minCostFromTo[0][n-1];
}
