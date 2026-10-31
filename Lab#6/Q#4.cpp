
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> result;

        int n = arr.size();

        for (int curr = n; curr > 1; curr--) {

            int maxIndex = 0;

            for (int i = 1; i < curr; i++) {
                if (arr[i] > arr[maxIndex]) {
                    maxIndex = i;
                }
            }

            if (maxIndex == curr - 1) {
                continue;
            }

            if (maxIndex != 0) {
                reverse(arr.begin(), arr.begin() + maxIndex + 1);
                result.push_back(maxIndex + 1);
            }

            reverse(arr.begin(), arr.begin() + curr);
            result.push_back(curr);
        }

        return result;
    }
};

int main() {
    vector<int> arr = {3, 2, 4, 1};

    Solution s;

    vector<int> result = s.pancakeSort(arr);

    cout << "Flip sequence: ";

    for (int k : result) {
        cout << k << " ";
    }

    cout << "\nSorted array: ";

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}
