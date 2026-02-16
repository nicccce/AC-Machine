#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long n=nums.size(),ans,cnt=0;
        vector<long long> dp(k);
        ans=dp[k-1]=cnt=accumulate(nums.begin(),nums.begin()+k,0ll);
        for(int i=k;i<n;i++){
            cnt=cnt+nums[i]-nums[i-k];
            dp[i%k]=max(dp[i%k],0ll)+cnt;
            ans = max(ans,dp[i%k]);
        }
        return ans;
    }
};