// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    string reorderSpaces(string text) {
        vector<string> words;
        string word = "";
        int space_cnt = 0;
        
        for (char c : text) {
            if (c == ' ') {
                space_cnt++;
                if (!word.empty()) {
                    words.push_back(word);
                    word = "";
                }
            } else {
                word += c;
            }
        }
        
        if (!word.empty()) {
            words.push_back(word);
        }
        
        if (words.size() == 1) {
            string result = words[0];
            result += string(space_cnt, ' ');
            return result;
        }
        
        int between = space_cnt / (words.size() - 1);
        int extra = space_cnt % (words.size() - 1);
        
        string result = "";
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i < words.size() - 1) {
                result += string(between, ' ');
            }
        }
        
        result += string(extra, ' ');
        return result;
    }
};