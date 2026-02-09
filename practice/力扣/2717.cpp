// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        int n = nums.size();
        int pos1 = -1, posN = -1;
        
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) pos1 = i;
            if(nums[i] == n) posN = i;
        }
        
        if(pos1 < posN) {
            // 当1在n前面时，移动1会使n的位置向后移1位，所以n需要移动的步数是(n-1-posN)
            return pos1 + (n - 1 - posN);
        } else {
            // 当1在n后面时，移动1不会影响n的位置，但移动n时，原本在n位置的元素会占据1原来的位置
            // 实际上，移动1时会使n之后的所有元素向后移一位（包括n），然后n还要移动到末尾
            // 所以n需要移动的步数是(n-1-(posN+1))，加上1是因为移动1时n向后移了一位
            return pos1 + (n - 1 - (posN + 1));
        }
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