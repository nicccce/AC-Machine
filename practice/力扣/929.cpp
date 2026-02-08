// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> uniqueEmails;
        
        for (string& email : emails) {
            string processedEmail = "";
            bool atFound = false;
            bool plusFound = false;
            
            for (char c : email) {
                if (c == '@') {
                    atFound = true;
                    plusFound = false;  // Reset plus flag for domain part
                    processedEmail += c;
                } else if (atFound) {
                    // In domain part, just add the character
                    processedEmail += c;
                } else {
                    // In local part
                    if (c == '+') {
                        plusFound = true;
                    } else if (c == '.') {
                        // Skip the dot in local part
                        continue;
                    } else if (!plusFound) {
                        // Add character if we haven't encountered '+' yet
                        processedEmail += c;
                    }
                }
            }
            
            uniqueEmails.insert(processedEmail);
        }
        
        return uniqueEmails.size();
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