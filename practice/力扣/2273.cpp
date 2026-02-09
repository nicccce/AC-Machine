#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isAnagram(const string& s1, const string& s2) {
    if (s1.length() != s2.length()) return false;
    string t1 = s1, t2 = s2;
    sort(t1.begin(), t1.end());
    sort(t2.begin(), t2.end());
    return t1 == t2;
}

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        result.push_back(words[0]);
        
        for (int i = 1; i < words.size(); i++) {
            if (!isAnagram(result.back(), words[i])) {
                result.push_back(words[i]);
            }
        }
        
        return result;
    }
};