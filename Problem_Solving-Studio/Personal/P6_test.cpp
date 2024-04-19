#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Polyomino {
    int height, width;
    bool placed = false;
    vector<vector<int>> shape;
};

int n, gridSize;
vector<Polyomino> polyominos;
vector<vector<int>> board;

void printBoard(){
    
    for(int i = 0 ; i < board.size(); i++){
        for(int j = 0 ; j < board.size() ; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isPossibleToPlace(const Polyomino &p, int x, int y) {
    // if (x + p.height > gridSize || y + p.width > gridSize) return false;
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
    
    cout << "[backtrack] (x, y): (" << x << ", " << y << ")" <<endl;
    
    if (x == gridSize) return true;

    int nextX = (y == gridSize - 1) ? x + 1 : x;
    int nextY = (y == gridSize - 1) ? 0 : y + 1;
    
    if (board[x][y]) return backtrack(nextX, nextY);
    
    cout << "---------------- Iteration start for (x, y): (" << x << ", " << y << ")-------------------" << endl;
    for (int i = 0; i < n; i++) {
        
        int height = polyominos[i].height;
        int width = polyominos[i].width;
        
        int x_with_offset = x + height > gridSize? gridSize - height : x;
        int y_with_offset = y + width > gridSize? gridSize - width : y;
        
        if (!polyominos[i].placed && isPossibleToPlace(polyominos[i], x_with_offset, y_with_offset)) {
            cout << "polyomino[" << i << "] can be placed at (" << x << ", " << y << ")" << endl;
            cout << "height: " << height << " | width: " << width << endl;
            placePolyomino(polyominos[i], x_with_offset, y_with_offset, i + 1);
            polyominos[i].placed = true;
            printBoard();
            if (backtrack(nextX, nextY)) return true;
            cout << "after ???" << endl;
            placePolyomino(polyominos[i], x_with_offset, y_with_offset, 0); // remove polyomino for backtracking
            polyominos[i].placed = false;
        }
    }
    cout << "---------------- Iteration end for (x, y): (" << x << ", " << y << ")-------------------\n" << endl;
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
        for (int i = 0; i < gridSize; i++) {
            for (int j = 0; j < gridSize; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }
    } else {
        cout << "No solution possible";
    }

    return 0;
}
