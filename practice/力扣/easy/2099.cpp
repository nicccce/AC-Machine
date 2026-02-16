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
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> indexedNums;
        for (int i = 0; i < nums.size(); i++) {
            indexedNums.push_back({nums[i], i});
        }
        
        // Sort by value in descending order
        sort(indexedNums.rbegin(), indexedNums.rend());
        
        // Get the indices of the k largest elements
        vector<int> indices;
        for (int i = 0; i < k; i++) {
            indices.push_back(indexedNums[i].second);
        }
        
        // Sort indices to maintain the original order
        sort(indices.begin(), indices.end());
        
        // Build the result subsequence
        vector<int> result;
        for (int idx : indices) {
            result.push_back(nums[idx]);
        }
        
        return result;
    }
};