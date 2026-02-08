// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                result[i] = 0;
            } else {
                int nextIndex = i + nums[i];
                
                // Handle negative indices by adding multiples of n until positive
                while (nextIndex < 0) {
                    nextIndex += n;
                }
                
                // Handle wrap-around for positive indices
                nextIndex %= n;
                
                result[i] = nums[nextIndex];
            }
        }
        
        return result;
    }
};