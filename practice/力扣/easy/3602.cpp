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

string toHex(int n) {
    if (n == 0) return "0";
    string result;
    while (n > 0) {
        int rem = n % 16;
        if (rem < 10) {
            result = char('0' + rem) + result;
        } else {
            result = char('A' + rem - 10) + result;
        }
        n /= 16;
    }
    return result;
}

string toBase36(long long n) {
    if (n == 0) return "0";
    string result;
    while (n > 0) {
        int rem = n % 36;
        if (rem < 10) {
            result = char('0' + rem) + result;
        } else {
            result = char('A' + rem - 10) + result;
        }
        n /= 36;
    }
    return result;
}

class Solution {
public:
    string concatHex36(int n) {
        long long square = 1LL * n * n;
        long long cube = 1LL * n * n * n;
        return toHex(square) + toBase36(cube);
    }
};