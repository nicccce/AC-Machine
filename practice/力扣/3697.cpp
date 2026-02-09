#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> res;
        ll p = 1;
        while (n) {
            int d = n % 10;
            if (d) res.push_back(d * p);
            n /= 10;
            p *= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};