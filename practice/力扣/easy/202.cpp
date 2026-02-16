// 
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

class Solution {
public:
    bool isHappy(int n) {
        auto getNext = [](int num) {
            int sum = 0;
            while (num > 0) {
                int digit = num % 10;
                sum += digit * digit;
                num /= 10;
            }
            return sum;
        };
        
        unordered_set<int> seen;
        while (n != 1 && !seen.count(n)) {
            seen.insert(n);
            n = getNext(n);
        }
        
        return n == 1;
    }
};