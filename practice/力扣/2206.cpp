// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        
        for (auto& [num, freq] : count) {
            if (freq % 2 != 0) {
                return false;
            }
        }
        
        return true;
    }
};