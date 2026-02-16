// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.length();
        for (int i = 0; i <= n - k; i++) {
            char c = s[i];
            bool same = true;
            for (int j = i; j < i + k; j++) {
                if (s[j] != c) {
                    same = false;
                    break;
                }
            }
            
            if (same) {
                bool valid = true;
                if (i > 0 && s[i - 1] == c) valid = false;
                if (i + k < n && s[i + k] == c) valid = false;
                
                if (valid) return true;
            }
        }
        return false;
    }
};