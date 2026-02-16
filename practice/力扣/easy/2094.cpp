// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> result;
        unordered_map<int, int> count;
        
        // Count the frequency of each digit
        for (int digit : digits) {
            count[digit]++;
        }
        
        // Try all possible 3-digit even numbers
        for (int num = 100; num < 1000; num += 2) { // Only even numbers
            int hundreds = num / 100;
            int tens = (num / 10) % 10;
            int units = num % 10;
            
            unordered_map<int, int> tempCount = count;
            
            // Check if we can form this number using available digits
            tempCount[hundreds]--;
            tempCount[tens]--;
            tempCount[units]--;
            
            if (tempCount[hundreds] >= 0 && tempCount[tens] >= 0 && tempCount[units] >= 0) {
                result.push_back(num);
            }
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