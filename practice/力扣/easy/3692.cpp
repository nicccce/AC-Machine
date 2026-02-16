// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char, int> freq; // Character frequency
        unordered_map<int, vector<char>> group; // Frequency to characters mapping
        
        // Count the frequency of each character
        for (char c : s) {
            freq[c]++;
        }
        
        // Group characters by their frequency
        for (auto& p : freq) {
            group[p.second].push_back(p.first);
        }
        
        // Find the largest group size, with preference to higher frequency in case of ties
        int maxGroupSize = 0;
        int bestFreq = 0;
        
        for (auto& p : group) {
            int currentGroupSize = p.second.size();
            int currentFreq = p.first;
            
            if (currentGroupSize > maxGroupSize || 
                (currentGroupSize == maxGroupSize && currentFreq > bestFreq)) {
                maxGroupSize = currentGroupSize;
                bestFreq = currentFreq;
            }
        }
        
        // Build the result string
        string result = "";
        for (char c : group[bestFreq]) {
            result += c;
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