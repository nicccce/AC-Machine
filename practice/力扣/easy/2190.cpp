// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int, int> count;
        int maxCount = 0;
        int result = 0;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == key) {
                count[nums[i + 1]]++;
                if (count[nums[i + 1]] > maxCount) {
                    maxCount = count[nums[i + 1]];
                    result = nums[i + 1];
                }
            }
        }
        
        return result;
    }
};