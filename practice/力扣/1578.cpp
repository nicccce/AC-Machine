#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0,maxx=0,n=neededTime.size();
        char nc='6';
        for(int i=0;i<n;i++){
            int nt=neededTime[i];
            if(colors[i]!=nc){
                ans+=nt-maxx;
                maxx=nt;
                nc=colors[i];
            }else{
                maxx=max(maxx,nt);
                ans+=nt;
            }
        }
        ans-=maxx;
        return ans;
    }
};