//
//  c1.c
//  PSS
//
//  Created by Bean's Macbook Pro on 2023/09/08.
//

/* input
 5 2 6
 1 2
 3 2
 3 4
 4 5
 5 2
 2 4
 
 5 3 7
 1 2
 3 2
 3 4
 4 5
 5 2
 2 4
 3 5
 */

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int n, k, f;
    if(scanf("%d %d %d", &n, &k, &f) != 3) return 0;
    
    int matrix[n][n]; // Adjacency Matrix
    
    int candidate[n]; // candidate for speical force team
    /* if candidate[a] == 1, it means index a+1 solider might be the one of the team.*/
    int candidate_size = 0;
    
    for(int i = 0 ; i < n ; i++){
        candidate[i] = 0;
        for(int j = 0 ; j < n ; j++)
            matrix[i][j] = 0;
    }
    int row, col;
    
    for(int i = 0; i < f ; i++){
        if(scanf("%d %d", &row, &col) != 2) return 0;
        matrix[row-1][col-1] = 1; // matrix의 인덱스는 0부터 시작하므로.
        matrix[col-1][row-1] = 1; // 대칭성
    }
    
    /* // printing test
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    */
    
    for(int i = 0 ; i < n ; i++){
        int cnt = 0;
        for(int j = 0 ; j < n ; j++)
            if(matrix[i][j] == 1) cnt++;
        if(cnt>=k) {candidate[i] = 1; candidate_size++;}
    }
    
    if(candidate_size < k+1) {printf("0"); return 0;}
    
    /* //test
    printf("\n");
    for(int i = 0 ; i < n ; i++) printf("%d ", candidate[i]);
    */
    
    /*
    1. candidate set에서 1인 요소들만 접근
    2. 해당 인덱스의 row에서, 인접한 것들 (1로 찍혀있는)이 candidate set에도 있는지 확인
        cnt로 개수셈 -> cnt가 k보다 작으면 candidate set에서 해당 인덱스 0으로
    */
    
    /*
    candidate set에 들어간 soldier들이
    "every member of the special force team has
     at least k friends in the special force team"
    만족하는지 검증.
     */
    
    int rmv_size = 0;
    
    for(int i = 0 ; i < n ; i++){
        if(candidate[i] == 1){
            int cnt = 0;
            for(int j = 0; j < n ; j++){
                if(matrix[i][j] == 1 && candidate[j] == 1) cnt++;
            }
            if(cnt < k){candidate[i] = 0; candidate_size--; rmv_size++;}
            if(candidate_size < k+1) {printf("0"); return 0;}
        }
    }
    
    while(rmv_size != 0){
        for(int i = 0 ; i < n ; i++){
            if(candidate[i] == 1){
                int cnt = 0;
                for(int j = 0; j < n ; j++){
                    if(matrix[i][j] == 1 && candidate[j] == 1) cnt++;
                }
                if(cnt < k){candidate[i] = 0; candidate_size--; rmv_size++;}
                if(candidate_size < k+1) {printf("0"); return 0;}
            }
        }
        rmv_size--;
    }
    
    printf("%d", candidate_size);
    
    return 0;
}
