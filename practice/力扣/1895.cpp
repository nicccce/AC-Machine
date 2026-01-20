#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int  n=grid.size(),m=grid[0].size(),ans=1;
        vector<vector<int>> prefixi(n+1,vector<int>(m+1,0)),
        prefixj(n+1,vector<int>(m+1,0)),
        prefixx(n+1,vector<int>(m+1,0)),
        prefixy(n+2,vector<int>(m+2,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                prefixi[i+1][j+1]=prefixi[i][j+1]+grid[i][j];
                prefixj[i+1][j+1]=prefixj[i+1][j]+grid[i][j];
                prefixx[i+1][j+1]=prefixx[i][j]+grid[i][j];
                prefixy[i+1][j+1]=prefixy[i][j+2]+grid[i][j];
            }
        }
        for(int k=1;k<=min(n,m);k++){
            for(int i=0;i+k-1<n;i++){
                for(int j=0;j+k-1<m;j++){
                    vector<int> sums;
                    sums.push_back(prefixx[i+k][j+k]-prefixx[i][j]);
                    sums.push_back(prefixy[i+k][j+1]-prefixy[i][j+k+1]);
                    for(int t=0;t<k;t++){
                        sums.push_back(prefixi[i+k][j+t+1]-prefixi[i][j+t+1]);
                        sums.push_back(prefixj[i+t+1][j+k]-prefixj[i+t+1][j]);
                    }
                    sort(sums.begin(),sums.end());
                    if(sums[0]==sums.back())
                    ans=max(ans,k);
                }
            }
        }
        return ans;
    }
};