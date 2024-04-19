#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Polyomino {
    int height, width;
    bool isPlaced = false;
    vector<vector<int>> shape;
};

int n, gridSize;
vector<Polyomino> polyominos;
vector<vector<int>> board;

void printBoard(){
    
    for(int i = 0 ; i < (int)board.size(); i++){
        for(int j = 0 ; j < (int)board.size() ; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isPossibleToPlace(const Polyomino &p, int x, int y) {
    for (int i = 0; i < p.height; i++) {
        for (int j = 0; j < p.width; j++) {
            if (p.shape[i][j] && board[x + i][y + j]) return false;
        }
    }
    return true;
}

void placePolyomino(const Polyomino &p, int x, int y, int id) {
    for (int i = 0; i < p.height; i++) {
        for (int j = 0; j < p.width; j++) {
            if (p.shape[i][j]) board[x + i][y + j] = id;
        }
    }
}

bool backtrack(int x, int y) {
    
    if (x == gridSize) return true;

    int nextX = (y == gridSize - 1) ? x + 1 : x;
    int nextY = (y == gridSize - 1) ? 0 : y + 1;
    
    if (board[x][y]) return backtrack(nextX, nextY);
    
    for (int i = 0; i < n; i++) {
        
        int height = polyominos[i].height;
        int width = polyominos[i].width;
        
        int x_with_offset = x + height > gridSize? gridSize - height : x;
        int y_with_offset = y + width > gridSize? gridSize - width : y;
        
        if (!polyominos[i].isPlaced && isPossibleToPlace(polyominos[i], x_with_offset, y_with_offset)) {
            
            placePolyomino(polyominos[i], x_with_offset, y_with_offset, i + 1);
            polyominos[i].isPlaced = true;
            if (backtrack(nextX, nextY)) return true;
            placePolyomino(polyominos[i], x_with_offset, y_with_offset, 0);
            polyominos[i].isPlaced = false;
        }
    }
    return false;
}

int main() {
    cin >> n;
    int totalBlocks = 0;
    
    for (int i = 0; i < n; i++) {
        int h, w;
        cin >> h >> w;

        Polyomino p{h, w, {}};
        for (int j = 0; j < h; j++) {
            
            vector<int> row;
            
            for(int k = 0 ; k < w ; k ++){
                int c;
                cin >> c;
                row.push_back(c);
                totalBlocks += c;
            }
            p.shape.push_back(row);
        }
        
        polyominos.push_back(p);
    }
    
    
    gridSize = ceil(sqrt(totalBlocks));
    double isSqrtFit = gridSize - sqrt(totalBlocks);
    if(isSqrtFit != 0) {
        cout << "No solution possible";
        return 0;
    }
    
    board = vector<vector<int>>(gridSize, vector<int>(gridSize, 0));

    if (backtrack(0, 0)) {
        printBoard();
    } else {
        cout << "No solution possible";
    }

    return 0;
}
