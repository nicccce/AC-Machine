#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll qpow(ll b, ll p, ll mod)
{
    ll r = 1;
    while (p)
    {
        if (p & 1)
            r = r * b % mod;
        b = b * b % mod, p >>= 1;
    }
    return r;
}

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int ans = 0;
        
        for (int j = 0; j < m; j++) {  // 遍历每一列
            for (int i = 1; i < n; i++) {  // 遍历每一行
                if (strs[i][j] < strs[i-1][j]) {  // 如果当前列不是按字典序非严格递增排列
                    ans++;
                    break;
                }
            }
        }
        
        return ans;
    }
};