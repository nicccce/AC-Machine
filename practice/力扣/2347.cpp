#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        bool f = true;
        for (int i = 1; i < 5; i++) {
            if (suits[i] != suits[0]) {
                f = false;
                break;
            }
        }
        if (f) return "Flush";
        
        map<int, int> cnt;
        for (int r : ranks) cnt[r]++;
        for (auto& p : cnt) {
            if (p.second >= 3) return "Three of a Kind";
        }
        for (auto& p : cnt) {
            if (p.second >= 2) return "Pair";
        }
        return "High Card";
    }
};