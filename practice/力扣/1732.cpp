#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int cur = 0, mx = 0;
        for (int g : gain) {
            cur += g;
            mx = max(mx, cur);
        }
        return mx;
    }
};