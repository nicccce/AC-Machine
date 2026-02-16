// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word = "";
        
        // Split s into words
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                words.push_back(word);
                word = "";
            } else {
                word += s[i];
            }
        }
        words.push_back(word);  // Add the last word
        
        if (pattern.length() != words.size()) {
            return false;
        }
        
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;
        
        for (int i = 0; i < pattern.length(); i++) {
            char c = pattern[i];
            string w = words[i];
            
            // Check if character already maps to a different word
            if (charToWord.count(c)) {
                if (charToWord[c] != w) {
                    return false;
                }
            } else {
                charToWord[c] = w;
            }
            
            // Check if word already maps to a different character
            if (wordToChar.count(w)) {
                if (wordToChar[w] != c) {
                    return false;
                }
            } else {
                wordToChar[w] = c;
            }
        }
        
        return true;
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