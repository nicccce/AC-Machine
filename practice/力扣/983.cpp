// https://leetcode.cn/problems/minimum-cost-for-tickets/description/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int dp[365]={0};int num=days.size();
        int day[3]={1,7,30};
        for(int i=0;i<num;i++)dp[i]=INT_MAX;
        dp[0]=min({costs[0],costs[1],costs[2]});
        for(int i=1;i<num;i++){
            for(int j=0;j<3;j++){
                int k=i;
                while(k>=0&&days[k]+day[j]>days[i]){
                    k--;
                }
                if(k==-1)dp[i]=min(dp[i],costs[j]);
                else dp[i]=min(dp[i],dp[k]+costs[j]);
            }
        }
        return dp[num-1];
    }
};