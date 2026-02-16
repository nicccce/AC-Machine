#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                // 检查移除子数组[i, j]后是否严格递增
                bool valid = true;
                vector<int> temp;
                
                // 添加子数组左边部分
                for (int k = 0; k < i; k++) {
                    temp.push_back(nums[k]);
                }
                
                // 添加子数组右边部分
                for (int k = j + 1; k < n; k++) {
                    temp.push_back(nums[k]);
                }
                
                // 检查是否严格递增
                for (int k = 1; k < temp.size(); k++) {
                    if (temp[k] <= temp[k-1]) {
                        valid = false;
                        break;
                    }
                }
                
                if (valid) {
                    count++;
                }
            }
        }
        
        return count;
    }
};