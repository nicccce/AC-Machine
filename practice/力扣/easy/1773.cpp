#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int cnt = 0;
        int idx = 0;
        if (ruleKey == "color") idx = 1;
        else if (ruleKey == "name") idx = 2;
        
        for (auto& item : items) {
            if (item[idx] == ruleValue) {
                cnt++;
            }
        }
        
        return cnt;
    }
};