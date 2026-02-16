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
    int findComplement(int num) {
        // Find the number of bits in num
        int bits = 0;
        int temp = num;
        while (temp) {
            bits++;
            temp >>= 1;
        }
        
        // Create a mask with all 1's for the number of bits
        // For example, if num has 3 bits, mask would be 111 (binary) = 7 (decimal)
        int mask = (1LL << bits) - 1;
        
        // XOR num with mask to get complement
        return num ^ mask;
    }
};