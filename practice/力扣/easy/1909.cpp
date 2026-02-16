#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            bool valid = true;
            for (int j = 0; j < n - 1; j++) {
                int left = j;
                int right = j + 1;
                if (left >= i) left++;
                if (right >= i) right++;
                if (left < n && right < n && nums[left] >= nums[right]) {
                    valid = false;
                    break;
                }
            }
            if (valid) return true;
        }
        return false;
    }
};