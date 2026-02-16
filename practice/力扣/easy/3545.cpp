// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int minDeletion(string s, int k) {
        // 统计每个字符的出现频率
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }
        
        // 将频率放入数组并排序
        vector<int> frequencies;
        for (auto& p : freq) {
            frequencies.push_back(p.second);
        }
        sort(frequencies.begin(), frequencies.end());
        
        // 如果不同字符数已经小于等于k，不需要删除
        if (frequencies.size() <= k) {
            return 0;
        }
        
        // 计算需要删除的字符数
        int deleteCount = 0;
        int excess = frequencies.size() - k; // 超出的字符种类数量
        
        // 删除出现频率最低的字符
        for (int i = 0; i < excess; i++) {
            deleteCount += frequencies[i];
        }
        
        return deleteCount;
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