// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> cnt;
        for (auto& d : dominoes) {
            if (d[0] > d[1]) {
                swap(d[0], d[1]);
            }
            cnt[{d[0], d[1]}]++;
        }
        
        int res = 0;
        for (auto& p : cnt) {
            int n = p.second;
            res += n * (n - 1) / 2;
        }
        return res;
    }
};