// https://leetcode.cn/problems/powx-n/description/?envType=problem-list-v2&envId=math
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
double qpow(double b, ll p)
{
    double r = 1;
    while (p)
    {
        if (p & 1)
            r = r * b;
        b = b * b, p >>= 1;
    }
    return r;
}
class Solution {
public:
    double myPow(double x, int n) {
        return n>=0?qpow(x,n):1.0/qpow(x,-(ll)n);
    }
};