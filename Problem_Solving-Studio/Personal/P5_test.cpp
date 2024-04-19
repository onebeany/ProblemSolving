#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector<int>& array, int key) {
    auto it = lower_bound(array.begin(), array.end(), key);
    if (it == array.end()) return -1;
    return it - array.begin();
}

void calculateLIS(const vector<int>& cards, vector<int>& LIS, bool ascending = true) {
    vector<int> tempList;
    for (int i = (ascending ? 0 : cards.size() - 1); 
         ascending ? i < cards.size() : i >= 0; 
         ascending ? i++ : i--) {
        int pos = binarySearch(tempList, cards[i]);
        if (pos == -1) {
            tempList.push_back(cards[i]);
            pos = tempList.size() - 1;
        } else {
            tempList[pos] = cards[i];
        }
        LIS[i] = pos + 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> cards(n);
    for(int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    vector<int> ascendLIS(n), descendLIS(n);
    calculateLIS(cards, ascendLIS, true);
    calculateLIS(cards, descendLIS, false);

    int result = 0;
    for (int i = 0; i < n; i++) {
        result = max(result, ascendLIS[i] + descendLIS[i] - 1);
    }

    cout << result << endl;
    return 0;
}

