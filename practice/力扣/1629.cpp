#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int mx = releaseTimes[0];
        char ans = keysPressed[0];
        int n = releaseTimes.size();
        for (int i = 1; i < n; i++) {
            int dur = releaseTimes[i] - releaseTimes[i-1];
            if (dur > mx || (dur == mx && keysPressed[i] > ans)) {
                mx = dur;
                ans = keysPressed[i];
            }
        }
        return ans;
    }
};