#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int, int> cnt;
        for (int x : nums)
            ++cnt[x];
        int ans = 0;
        for (int x : nums)
            for (int i : {x - k, x, x + k}) 
                if (nums[0] <= i && i <= nums.back()) {
                    int nc = upper_bound(nums.begin(),nums.end(), i + k) - lower_bound(nums.begin(),nums.end(), i - k);
                    ans = max(ans, min(numOperations + cnt[i], nc));
                }
        return ans;
    }
};