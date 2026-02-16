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
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        unordered_map<string, int> businessOrder = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };
        
        vector<tuple<string, string, int>> validCoupons;
        
        for (int i = 0; i < code.size(); i++) {
            // Check if code is not empty and contains only alphanumeric characters and underscores
            bool validCode = !code[i].empty();
            for (char c : code[i]) {
                if (!isalnum(c) && c != '_') {
                    validCode = false;
                    break;
                }
            }
            
            // Check if businessLine is valid
            bool validBusiness = businessOrder.count(businessLine[i]) > 0;
            
            // Check if coupon is active
            bool validActive = isActive[i];
            
            if (validCode && validBusiness && validActive) {
                validCoupons.push_back({businessLine[i], code[i], businessOrder[businessLine[i]]});
            }
        }
        
        // Sort valid coupons by business line and then by code lexicographically
        sort(validCoupons.begin(), validCoupons.end(), [](const tuple<string, string, int>& a, const tuple<string, string, int>& b) {
            if (get<2>(a) != get<2>(b)) {
                return get<2>(a) < get<2>(b);
            }
            return get<1>(a) < get<1>(b);
        });
        
        vector<string> result;
        for (auto& coupon : validCoupons) {
            result.push_back(get<1>(coupon));
        }
        
        return result;
    }
};