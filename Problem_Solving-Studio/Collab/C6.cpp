#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canPlace(const vector<int>& poles, int n, int k, int minDist) {
    int placedPoles = 1;    
    int lastPlacedPos = poles[0];

    for (int i = 1; i < n; i++) {
        if (poles[i] - lastPlacedPos >= minDist) {
            placedPoles++;
            lastPlacedPos = poles[i];
        }
    }

    return placedPoles >= k;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> poles(n);
    for (int i = 0; i < n; i++) {
        cin >> poles[i];
    }

    sort(poles.begin(), poles.end());

    int low = poles[1] - poles[0], high = poles[n - 1] - poles[0], result = 0;
    for (int i = 2; i < n; i++) {
        low = min(low, poles[i] - poles[i-1]);
        }
    

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPlace(poles, n, k, mid)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << result << endl;

    return 0;
}
