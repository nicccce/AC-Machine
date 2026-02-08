// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            // If left element is even, move left pointer forward
            if (nums[left] % 2 == 0) {
                left++;
            } 
            // If right element is odd, move right pointer backward
            else if (nums[right] % 2 == 1) {
                right--;
            } 
            // If left is odd and right is even, swap them
            else {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
        
        return nums;
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