// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int n = nums.size();
        int maxPrime = 0;
        
        // 检查主对角线和反对角线上的元素
        for (int i = 0; i < n; i++) {
            // 主对角线
            if (isPrime(nums[i][i])) {
                maxPrime = max(maxPrime, nums[i][i]);
            }
            
            // 反对角线
            if (isPrime(nums[i][n - i - 1])) {
                maxPrime = max(maxPrime, nums[i][n - i - 1]);
            }
        }
        
        return maxPrime;
    }
    
private:
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        
        return true;
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