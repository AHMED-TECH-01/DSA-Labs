#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
int findLHS(vector<int>& nums) {
    // Count how many times each value appears
    unordered_map<int, int> freq;
    for (int x : nums) freq[x]++;

    // For each value x, check if x + 1 also exists
    int best = 0;
    for (auto& p : freq) {
        int x = p.first;
        if (freq.count(x + 1)) {
            best = max(best, p.second + freq[x + 1]);
        }
    }
    return best;
}

void runTest(vector<int> nums) {
    cout << "Input: [";
    for (size_t i = 0; i < nums.size(); i++)
        cout << nums[i] << (i + 1 < nums.size() ? "," : "");
    cout << "] " << endl << 
      "Output: " << findLHS(nums) << endl;
}

int main() {
    runTest({1, 3, 2, 2, 5, 2, 3, 7});  
    runTest({1, 2, 3, 4});              
                          
    return 0;
}