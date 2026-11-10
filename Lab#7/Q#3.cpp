#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    vector<vector<int>> result;
    if (intervals.empty()) return result;
    sort(intervals.begin(), intervals.end());
    result.push_back(intervals[0]);
    for (int i = 1; i < (int)intervals.size(); i++) {
        vector<int>& last = result.back();

        if (intervals[i][0] <= last[1]) {
            last[1] = max(last[1], intervals[i][1]);
        } else {
            result.push_back(intervals[i]);
        }
    }
    return result;
}

void printIntervals(const vector<vector<int>>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        cout << "[" << v[i][0] << "," << v[i][1] << "]";
        if (i + 1 < v.size()) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    vector<vector<vector<int>>> tests = {
        {{3, 6}, {7, 9}},
        {{1, 3}, {2, 6}, {3, 0}, {9, 8}},
        {{8, 1}, {1, 7}, {2, 6}},
        {{1, 0}, {2, 6}, {7, 5}},
        {{5, 6}}
    };

    for (auto& t : tests) {
        cout << "Input:  "; printIntervals(t);
        cout << "Output: "; printIntervals(mergeIntervals(t));
        cout << endl;
    }
    return 0;
}