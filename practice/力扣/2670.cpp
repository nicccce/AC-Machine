// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        
        for(int i = 0; i < n; i++) {
            // 计算前缀不同元素个数
            set<int> prefixSet;
            for(int j = 0; j <= i; j++) {
                prefixSet.insert(nums[j]);
            }
            int prefixCount = prefixSet.size();
            
            // 计算后缀不同元素个数
            set<int> suffixSet;
            for(int j = i + 1; j < n; j++) {
                suffixSet.insert(nums[j]);
            }
            int suffixCount = suffixSet.size();
            
            result[i] = prefixCount - suffixCount;
        }
        
        return result;
    }
};

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

int ex_gcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    else
    {
        int d = ex_gcd(b, a % b, y, x);
        y -= a / b * x;
        return d;
    }
}

int solve_linear_congruence_equation(int a, int b, int n)
{
    int x, y;
    int d = ex_gcd(a, n, x, y);
    if (b % d)
        return -1;
    n /= d;
    return ((long long)x * (b / d) % n + n) % n;
}