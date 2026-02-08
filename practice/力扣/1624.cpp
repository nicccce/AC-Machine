// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> first(26, -1);
        int max_len = -1;
        
        for (int i = 0; i < s.length(); i++) {
            int c = s[i] - 'a';
            if (first[c] == -1) {
                first[c] = i;
            } else {
                max_len = max(max_len, i - first[c] - 1);
            }
        }
        
        return max_len;
    }
};