// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int t = n;
        int bits = 0;
        while(t) {
            t >>= 1;
            bits++;
        }
        int mask = (1 << bits) - 1;
        return n ^ mask;
    }
};