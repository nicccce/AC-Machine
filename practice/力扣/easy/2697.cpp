// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.length();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - 1 - i]) {
                char c = min(s[i], s[n - 1 - i]);
                s[i] = c;
                s[n - 1 - i] = c;
            }
        }
        return s;
    }
};