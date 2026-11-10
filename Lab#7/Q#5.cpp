#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool carPooling(vector<vector<int>>& trips, int capacity) {
    map<int, int> change;   
    
    for (auto& t : trips) {
        change[t[1]] += t[0];   // pick up at 'from'
        change[t[2]] -= t[0];   // drop off at 'to'
    }

    int current = 0;
    for (auto& p : change) {
        current += p.second;
        if (current > capacity) return false;
    }
    return true;
}

void runTest(vector<vector<int>> trips, int capacity) {
    cout << "capacity = " << capacity << "  ->  "
         << (carPooling(trips, capacity) ? "true" : "false") << endl;
}

int main() {
    runTest({{2, 1, 5}, {3, 3, 7}}, 4);   // false
    runTest({{2, 1, 5}, {3, 3, 7}}, 5);   // true
       runTest({{3, 2, 7}, {3, 7, 9}, {8, 3, 9}}, 11);  // true (drop-off at 7 frees seats first)
    runTest({{3, 2, 7}, {3, 7, 9}, {8, 3, 9}}, 10);  // false
    runTest({{5, 1, 2}}, 4);              // false
    return 0;
}