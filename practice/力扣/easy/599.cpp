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
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> indexMap;
        for (int i = 0; i < list1.size(); i++) {
            indexMap[list1[i]] = i;
        }
        
        int minSum = INT_MAX;
        vector<string> result;
        
        for (int j = 0; j < list2.size(); j++) {
            string restaurant = list2[j];
            if (indexMap.count(restaurant)) {
                int sum = indexMap[restaurant] + j;
                if (sum < minSum) {
                    minSum = sum;
                    result.clear();
                    result.push_back(restaurant);
                } else if (sum == minSum) {
                    result.push_back(restaurant);
                }
            }
        }
        
        return result;
    }
};