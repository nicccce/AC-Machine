// https://leetcode.cn/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/solutions/101737/yuan-su-he-xiao-yu-deng-yu-yu-zhi-de-zheng-fang-2/?envType=daily-question&envId=2026-01-19
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> sum(n+1,vector<int>(m+1,0));
        vector<vector<int>> prefixi(n+1,vector<int>(m,0));
        vector<vector<int>> prefixj(n+1,vector<int>(m,0));
        for(int i=0;i<n;i++){
            prefixj[i][0]=mat[i][0];
        }for(int j=0;j<m;j++){
            prefixi[0][j]=mat[0][j];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0){
                    prefixi[0][j]=mat[0][j];
                }else{
                    prefixi[i][j]=prefixi[i-1][j]+mat[i][j];
                }
                if(j==0){
                    prefixj[i][0]=mat[i][0];
                }else{
                    prefixj[i][j]=prefixj[i][j-1]+mat[i][j];
                }
            }
        }
        int ans=0;
        cout<<prefixi[0][0]<<prefixi[1][0]<<endl;
        for(int x=1;x<=min(n,m);x++){
            for(int i=x-1;i<n;i++){
                for(int j=x-1;j<m;j++){
                    sum[i][j]+=prefixi[i][j-x+1]-prefixi[i-x+1][j-x+1]+prefixj[i-x+1][j]-prefixj[i-x+1][j-x+1]+mat[i-x+1][j-x+1];
                    if(sum[i][j]<=threshold){
                        ans=x;
                    }
                }
            }
            if(ans!=x){
                break;
            }
        }
        return ans;
    }
};