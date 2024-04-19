#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Polyomino {
    int height, width;
    vector<vector<int>> shape;
};

vector<Polyomino> polyominos;
vector<vector<int>> square;
int squareSize;


void printSquare(){
    
    for(int i = 0 ; i < squareSize; i++){
        for(int j = 0 ; j < squareSize ; j++){
            cout << square[i][j] << " ";
        }
        cout << endl;
    }
}

bool isPossibleToPlace(const Polyomino &p, int x, int y) {
    for (int i = 0; i < p.height; i++) {
        for (int j = 0; j < p.width; j++) {
            if (p.shape[i][j] && square[x + i][y + j]) return false;
        }
    }
    return true;
}

void placePolyomino(const Polyomino &p, int x, int y, int id) {
    for (int i = 0; i < p.height; i++) {
        for (int j = 0; j < p.width; j++) {
            if (p.shape[i][j]) square[x + i][y + j] = id;
        }
    }
}

bool canMakeSquare(Polyomino &p, int id){
    
    for(int i = 0 ; i < (squareSize+1) - p.height ; i++){
        for(int j = 0 ; j < (squareSize+1) - p.width ; j++){
            if(isPossibleToPlace(p, i, j)) {
                placePolyomino(p, i, j, id);
                if(id == polyominos.size()) return true;
                int new_id = id + 1;
                if(canMakeSquare(polyominos[id], new_id)) return true;
                placePolyomino(p, i, j, 0);
            }
        }
    }
    
    return false;
    
}

int main(){
    
    int n, totalBlocks = 0;
    cin >> n;
    
    
    for(int i = 0 ; i < n ; i++){
        
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
    
    squareSize = ceil(sqrt(totalBlocks));
    double isSqrtFit = squareSize - sqrt(totalBlocks);

    if(isSqrtFit != 0) {
        cout << "No solution possible";
        return 0;
    }
    
    square = vector<vector<int>>(squareSize, vector<int>(squareSize, 0));
    
    if(canMakeSquare(polyominos[0], 1)){
        printSquare();
    } else {
        cout << "No solution possible";
    }
    
}
