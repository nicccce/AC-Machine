// https://leetcode.cn/problems/count-number-of-trapezoids-i/?envType=daily-question&envId=2025-11-27
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        ll res = 0,sum=0;
        int mod = 1e9+7;
        map<ll,ll> mp;
        for(auto &p:points){
            mp[p[1]]++;
        }
        for(auto [k,v]:mp){
            v=v*(v-1)/2%mod;
            res+=v*sum%mod;
            res%=mod;
            sum+=v;
        }
        return res;
    }
};