#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int cntS[26] = {0}, cntT[26] = {0};
        for (char c : s) cntS[c - 'a']++;
        for (char c : target) cntT[c - 'a']++;
        int ans = INT_MAX;
        for (char c : target) {
            if (cntT[c - 'a'] > 0) {
                ans = min(ans, cntS[c - 'a'] / cntT[c - 'a']);
            }
        }
        return ans;
    }
};