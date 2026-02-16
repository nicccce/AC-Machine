#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int smallestNumber(int n) {
        int bits = 0;
        int temp = n;
        while (temp) {
            bits++;
            temp >>= 1;
        }
        return (1 << bits) - 1;
    }
};