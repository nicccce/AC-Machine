#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        auto toMin = [](string t) {
            return (t[0]-'0')*600 + (t[1]-'0')*60 + (t[3]-'0')*10 + (t[4]-'0');
        };
        int s1 = toMin(event1[0]), e1 = toMin(event1[1]);
        int s2 = toMin(event2[0]), e2 = toMin(event2[1]);
        return max(s1, s2) <= min(e1, e2);
    }
};