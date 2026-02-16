// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    string reverseByType(string s) {
        vector<char> letters, specials;
        vector<int> letter_pos, special_pos;
        
        for (int i = 0; i < s.length(); i++) {
            if (isalpha(s[i])) {
                letters.push_back(s[i]);
                letter_pos.push_back(i);
            } else {
                specials.push_back(s[i]);
                special_pos.push_back(i);
            }
        }
        
        reverse(letters.begin(), letters.end());
        reverse(specials.begin(), specials.end());
        
        string result = s;
        for (int i = 0; i < letter_pos.size(); i++) {
            result[letter_pos[i]] = letters[i];
        }
        for (int i = 0; i < special_pos.size(); i++) {
            result[special_pos[i]] = specials[i];
        }
        
        return result;
    }
};