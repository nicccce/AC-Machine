// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        double min_avg = DBL_MAX;
        
        for (int i = 0; i < n / 2; i++) {
            double avg = (nums[i] + nums[n - 1 - i]) / 2.0;
            min_avg = min(min_avg, avg);
        }
        
        return min_avg;
    }
};