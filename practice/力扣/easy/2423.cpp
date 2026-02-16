// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> freq(26, 0);
        for(char c : word) {
            freq[c - 'a']++;
        }
        
        for(int i = 0; i < 26; i++) {
            if(freq[i] == 0) continue;
            
            // 尝试删除一个字符
            freq[i]--;
            
            // 检查是否所有非零频率都相同
            set<int> uniqueFreq;
            for(int f : freq) {
                if(f > 0) uniqueFreq.insert(f);
            }
            
            if(uniqueFreq.size() <= 1) {
                return true;
            }
            
            // 撤销删除
            freq[i]++;
        }
        
        return false;
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