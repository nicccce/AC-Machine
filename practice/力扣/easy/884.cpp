// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> count;
        
        // Split and count words in s1
        string word;
        istringstream iss1(s1);
        while (iss1 >> word) {
            count[word]++;
        }
        
        // Split and count words in s2
        istringstream iss2(s2);
        while (iss2 >> word) {
            count[word]++;
        }
        
        vector<string> result;
        for (auto& [w, c] : count) {
            if (c == 1) {
                result.push_back(w);
            }
        }
        
        return result;
    }
};