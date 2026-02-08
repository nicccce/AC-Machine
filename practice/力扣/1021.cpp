// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int depth = 0;
        for (char c : s) {
            if (c == '(') {
                depth++;
                if (depth > 1) {
                    res += c;
                }
            } else {
                depth--;
                if (depth > 0) {
                    res += c;
                }
            }
        }
        return res;
    }
};