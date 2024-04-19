#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

void unionSets(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b)
        parent[a] = b;
}

int main() {
    int n, m;
    cin >> n >> m;

    parent.resize(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) {
        parent[i] = i;
    }

    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;

        int x_opposite = x + n;
        int y_opposite = y + n;

        if (find(x) == find(y)) {
            cout << i << endl;
            return 0;
        }

        unionSets(x, y_opposite);
        unionSets(y, x_opposite);
        
        for(int i = 1 ; i <= 2*n ; i++){
            cout << parent[i] << " ";
        }
        cout << endl;
    }

    cout << "All requests can be satisfied." << endl;
    return 0;
}
