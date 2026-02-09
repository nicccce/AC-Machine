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
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> order;
        for (int i = 0; i < arr2.size(); i++) {
            order[arr2[i]] = i;
        }
        
        sort(arr1.begin(), arr1.end(), [&](int a, int b) {
            if (order.count(a) && order.count(b)) {
                return order[a] < order[b];
            } else if (order.count(a)) {
                return true;
            } else if (order.count(b)) {
                return false;
            } else {
                return a < b;
            }
        });
        
        return arr1;
    }
};