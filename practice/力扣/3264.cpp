#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while (k--) {
            int minIdx = 0;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] < nums[minIdx]) {
                    minIdx = i;
                }
            }
            nums[minIdx] *= multiplier;
        }
        return nums;
    }
};