// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int min_prefix = 0;
        int sum = 0;
        for (int x : nums) {
            sum += x;
            min_prefix = min(min_prefix, sum);
        }
        return max(1, 1 - min_prefix);
    }
};