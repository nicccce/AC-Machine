#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            // 从左边找到第一个元音字母
            while (left < right && vowels.find(s[left]) == vowels.end()) {
                left++;
            }
            
            // 从右边找到第一个元音字母
            while (left < right && vowels.find(s[right]) == vowels.end()) {
                right--;
            }
            
            // 交换两个元音字母
            if (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
        }
        
        return s;
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