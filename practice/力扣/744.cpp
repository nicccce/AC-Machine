// https://leetcode.cn/problems/find-smallest-letter-greater-than-target/?envType=daily-question&envId=2026-01-31
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll qpow(ll b, ll p, ll mod)
{
    ll r = 1;
    while (p)
    {
        if (p & 1)
            r = r * b % mod;
        b = b * b % mod, p >>= 1;
    }
    return r;
}
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans='z'+1;
        for(auto i:letters)if(i>target&&i<ans)ans=i;
        if(ans=='z'+1)ans=letters[0];
        return ans;
    }
};