#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(int array[], int n , int key){
    
    int low = 0;
    int high = n - 1;
    int result = -1;

    while(low <= high){
        int mid = low + (high - low) / 2;
        if(array[mid] < key) low = mid + 1;
        else {
            result = mid;
            high = mid - 1;
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    int cards[n];
    for(int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    if(n == 1) {
        cout << 1 << endl;
        return 0;
    }

    int ascendList[n], ascendLIS[n];
    int descendList[n], descendLIS[n];

    for(int i = 0, k = 0 ; i < n ; i++){
        int pos = binarySearch(ascendList, k, cards[i]);
        if(pos == -1){
            pos = k;
            k++;
        }
        ascendList[pos] = cards[i];
        ascendLIS[i] = pos + 1; 
    }

    for(int i = n - 1, k = 0 ; i >= 0 ; i--){
        int pos = binarySearch(descendList, k, cards[i]);
        if(pos == -1){
            pos = k;
            k++;
        }
        descendList[pos] = cards[i];
        descendLIS[i] = pos + 1; 
    }

    int result = 0;
    for(int i = 0 ; i < n ; i++){
        result = max(result, ascendLIS[i] + descendLIS[i]);
    }

    cout << result - 1;

    return 0;
}


