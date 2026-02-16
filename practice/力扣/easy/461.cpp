#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int z = x ^ y;
        int cnt = 0;
        while (z) {
            cnt += z & 1;
            z >>= 1;
        }
        return cnt;
    }
};