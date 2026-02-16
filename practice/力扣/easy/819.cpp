#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        // 将禁用词放入集合中
        set<string> bannedSet(banned.begin(), banned.end());
        
        // 将段落转换为小写并分割单词
        for (char &c : paragraph) {
            if (c == '!' || c == '?' || c == '\'' || c == ',' || c == ';' || c == '.') {
                c = ' ';
            } else {
                c = tolower(c);
            }
        }
        
        map<string, int> count;
        stringstream ss(paragraph);
        string word;
        
        while (ss >> word) {
            if (bannedSet.find(word) == bannedSet.end()) {
                count[word]++;
            }
        }
        
        // 找到出现次数最多的单词
        string result = "";
        int maxCount = 0;
        for (auto& p : count) {
            if (p.second > maxCount) {
                maxCount = p.second;
                result = p.first;
            }
        }
        
        return result;
    }
};