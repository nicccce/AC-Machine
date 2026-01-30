// https://leetcode.cn/problems/count-number-of-trapezoids-ii/description/?envType=daily-question&envId=2025-11-27
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        map<pair<ll,ll>,map<ll,ll>>mp;
        int n = points.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ll dx=points[j][0]-points[i][0];
                ll dy=points[j][1]-points[i][1];
                if(dx==0){
                    mp[{1,0}][points[i][0]]++;
                    continue;
                }else if(dy==0){
                    mp[{0,1}][points[i][1]]++;
                    continue;
                }
                ll g=__gcd(dx,dy);
                dx/=g;dy/=g;
                ll c=dy*points[i][0]-dx*points[i][1];
                mp[{dx,dy}][c]++;
            }
        }
        ll res=0;
        for(auto &it:mp){
            ll sum=0;
            for(auto &jt:it.second){
                ll cnt=jt.second;
                res+=cnt*sum;
                sum+=cnt;
            }
        }
        map<pair<ll,ll>,map<pair<ll,ll>,ll>>parals;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ll midx=points[j][0]+points[i][0];
                ll midy=points[j][1]+points[i][1];
                ll dx=points[j][0]-points[i][0];
                ll dy=points[j][1]-points[i][1];
                if(dx==0){
                    parals[{midx,midy}][{1,0}]++;
                    continue;
                }else if(dy==0){
                    parals[{midx,midy}][{0,1}]++;
                    continue;
                }
                ll g=__gcd(dx,dy);
                dx/=g;dy/=g;
                parals[{midx,midy}][{dx,dy}]++;
            }
        }
        for(auto &it:parals){
            int sum=0;
            for(auto &jt:it.second){
                ll cnt=jt.second;
                res-=cnt*sum;
                sum+=cnt;
            }
        }
        return res;
    }
};