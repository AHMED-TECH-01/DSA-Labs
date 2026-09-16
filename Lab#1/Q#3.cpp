#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MedianFinder
{
private:
    vector<int> nums;
public:
    MedianFinder(){}

    void addNum(int num)
    {
        nums.push_back(num);}

    double findMedian()
    {
        sort(nums.begin(), nums.end());

        int n = nums.size();

        if (n % 2 == 1) return nums[n / 2];
       
        else{
            return (nums[n / 2 - 1] + nums[n / 2]) / 2.0;
        }}
    
};

int main()
{
    MedianFinder medianFinder;
    medianFinder.addNum(1);
    medianFinder.addNum(2);
    cout << "Median = " << medianFinder.findMedian() << endl;
    medianFinder.addNum(3);
    cout << "Median = " << medianFinder.findMedian() << endl;
    return 0;
}