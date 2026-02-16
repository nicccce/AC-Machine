// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int binaryGap(int n) {
        int last = -1, max_gap = 0;
        int pos = 0;
        
        while (n > 0) {
            if (n & 1) {
                if (last != -1) {
                    max_gap = max(max_gap, pos - last);
                }
                last = pos;
            }
            n >>= 1;
            pos++;
        }
        
        return max_gap;
    }
};