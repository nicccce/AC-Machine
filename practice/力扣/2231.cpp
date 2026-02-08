// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        vector<int> digits;
        
        // Convert number to a vector of digits
        for (char c : s) {
            digits.push_back(c - '0');
        }
        
        vector<int> odd, even;
        
        // Separate odd and even digits
        for (int digit : digits) {
            if (digit % 2 == 0) {
                even.push_back(digit);
            } else {
                odd.push_back(digit);
            }
        }
        
        // Sort both vectors in descending order to get maximum values
        sort(odd.begin(), odd.end(), greater<int>());
        sort(even.begin(), even.end(), greater<int>());
        
        // Reconstruct the number
        int oddIndex = 0, evenIndex = 0;
        for (int i = 0; i < digits.size(); i++) {
            if (digits[i] % 2 == 0) {
                digits[i] = even[evenIndex++];
            } else {
                digits[i] = odd[oddIndex++];
            }
        }
        
        // Convert back to integer
        int result = 0;
        for (int digit : digits) {
            result = result * 10 + digit;
        }
        
        return result;
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