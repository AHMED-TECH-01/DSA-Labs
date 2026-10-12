
#include <iostream>
#include <algorithm>
using namespace std;

int maximumToys(int arr[], int n, int K) {
    sort(arr, arr + n);

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] <= K) {
            K -= arr[i];
            count++;
        } else {
            break;
        }
    }

    return count;
}

int main() {
    int arr[] = {1, 12, 5, 111, 200, 1000, 10};
    int n = 7;
    int K = 50;

    cout << maximumToys(arr, n, K);

    return 0;
}
