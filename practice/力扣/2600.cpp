// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        // To maximize the sum, we should pick items in this order:
        // 1. Pick as many 1's as possible
        // 2. Then pick 0's
        // 3. Finally pick -1's only if necessary
        
        int sum = 0;
        
        // Pick 1's first
        int onesToPick = min(k, numOnes);
        sum += onesToPick;
        k -= onesToPick;
        
        // Pick 0's next
        int zerosToPick = min(k, numZeros);
        k -= zerosToPick;
        
        // Pick -1's if there are still items to pick
        int negOnesToPick = min(k, numNegOnes);
        sum -= negOnesToPick;
        
        return sum;
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