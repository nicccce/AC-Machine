// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> count, first;
        int degree = 0;
        int min_len = INT_MAX;
        
        for (int i = 0; i < nums.size(); i++) {
            if (first.count(nums[i]) == 0) {
                first[nums[i]] = i;
            }
            
            count[nums[i]]++;
            
            if (count[nums[i]] > degree) {
                degree = count[nums[i]];
                min_len = i - first[nums[i]] + 1;
            } else if (count[nums[i]] == degree) {
                min_len = min(min_len, i - first[nums[i]] + 1);
            }
        }
        
        return min_len;
    }
};