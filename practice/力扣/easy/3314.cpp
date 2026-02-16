// https://leetcode.cn/problems/construct-the-minimum-bitwise-array-i/description/?envType=daily-question&envId=2026-01-20
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int x=nums[i];
            if(x&1)
            ans[i]=((x&(x-((x^(x+1))>>1)))|((x^(x+1))>>2));
            else
            ans[i]=-1;
        }
        return ans;
    }
};