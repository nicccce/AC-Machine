#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> cnt1, cnt2;
        for (auto& w : words1) cnt1[w]++;
        for (auto& w : words2) cnt2[w]++;
        int ans = 0;
        for (auto& w : words1) {
            if (cnt1[w] == 1 && cnt2[w] == 1) ans++;
        }
        return ans;
    }
};