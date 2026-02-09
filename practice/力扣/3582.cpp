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
    string generateTag(string caption) {
        string res = "#";
        bool first = true;
        string word = "";
        
        for (int i = 0; i <= caption.length(); i++) {
            if (i == caption.length() || caption[i] == ' ') {
                if (!word.empty()) {
                    if (first) {
                        first = false;
                        for (char c : word) {
                            res += tolower(c);
                        }
                    } else {
                        res += toupper(word[0]);
                        for (int j = 1; j < word.length(); j++) {
                            res += tolower(word[j]);
                        }
                    }
                    word = "";
                }
            } else {
                if (isalpha(caption[i])) {
                    word += caption[i];
                }
            }
        }
        
        if (res.length() > 100) {
            res = res.substr(0, 100);
        }
        
        return res;
    }
};