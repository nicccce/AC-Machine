// https://leetcode.cn/problems/minimize-maximum-pair-sum-in-array/?envType=daily-question&envId=2025-11-27
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int res = 0;
        for(int i = 0;i<n/2;i++){
            res = max(res,nums[i]+nums[n-1-i]);
        }
        return res;
    }
};