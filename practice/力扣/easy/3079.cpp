#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int sum = 0;
        for (int x : nums) {
            int mx = 0, t = x;
            while (t) {
                mx = max(mx, t % 10);
                t /= 10;
            }
            string s = to_string(x);
            string r(s.size(), char('0' + mx));
            sum += stoi(r);
        }
        return sum;
    }
};