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
    vector<string> findWords(vector<string>& words) {
        string row1 = "qwertyuiop", row2 = "asdfghjkl", row3 = "zxcvbnm";
        unordered_map<char, int> charToRow;
        
        for (char c : row1) charToRow[c] = 1;
        for (char c : row1) charToRow[toupper(c)] = 1;
        for (char c : row2) charToRow[c] = 2;
        for (char c : row2) charToRow[toupper(c)] = 2;
        for (char c : row3) charToRow[c] = 3;
        for (char c : row3) charToRow[toupper(c)] = 3;
        
        vector<string> result;
        
        for (string word : words) {
            int row = charToRow[word[0]];
            bool sameRow = true;
            
            for (char c : word) {
                if (charToRow[c] != row) {
                    sameRow = false;
                    break;
                }
            }
            
            if (sameRow) {
                result.push_back(word);
            }
        }
        
        return result;
    }
};