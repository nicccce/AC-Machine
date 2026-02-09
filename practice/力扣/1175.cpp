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
    int numPrimeArrangements(int n) {
        const int MOD = 1000000007;
        
        auto isPrime = [](int num) -> bool {
            if (num < 2) return false;
            if (num == 2) return true;
            if (num % 2 == 0) return false;
            for (int i = 3; i * i <= num; i += 2) {
                if (num % i == 0) return false;
            }
            return true;
        };
        
        int primeCount = 0;
        for (int i = 1; i <= n; i++) {
            if (isPrime(i)) {
                primeCount++;
            }
        }
        
        int nonPrimeCount = n - primeCount;
        
        long long result = 1;
        for (int i = 1; i <= primeCount; i++) {
            result = (result * i) % MOD;
        }
        for (int i = 1; i <= nonPrimeCount; i++) {
            result = (result * i) % MOD;
        }
        
        return result;
    }
};