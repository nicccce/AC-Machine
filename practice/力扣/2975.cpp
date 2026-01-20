// https://leetcode.cn/problems/maximum-square-area-by-removing-fences-from-a-field/?envType=daily-question&envId=2026-01-20
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        vector<ll> hs,vs;
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        for(int i=0;i<hFences.size();i++){
            for(int j=i+1;j<hFences.size();j++){
                hs.push_back(abs(hFences[j]-hFences[i]));
            }
        }
        for(int i=0;i<vFences.size();i++){
            for(int j=i+1;j<vFences.size();j++){
                vs.push_back(abs(vFences[j]-vFences[i]));
            }
        }
        ll ans=0;
        sort(hs.begin(),hs.end(),greater<ll>());
        sort(vs.begin(),vs.end(),greater<ll>());
        int i=0,j=0;
        while(i<hs.size() && j<vs.size()){
            if(hs[i]==vs[j]){
                ans=hs[i];
                break;
            }
            else if(hs[i]>vs[j]) i++;
            else j++;
        }

        return ans==0?-1:ans%1000000007*ans%1000000007;
    }
};