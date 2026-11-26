#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n,x,y;
        cin>>n>>x>>y;
        int b=1;
        for(int i=0;i<n;i++)b*=6;
        vector<double> dp0={0,b},dp1;
        for(int i=1;i<=n;i++){
            dp1=vector<double>((1<<i)+1,b);
            dp1[0]=0;
            for(int j=1;j<=(1<<i);j++){
                for(int k=0;k<=j/2;k++){
                    int j1=k,j2=j-k; 
                    if(j2<=(1<<(i-1))&&j1<=(1<<(i-1)))
                    dp1[j]=min(dp1[j],max(dp0[j2]/2,(dp0[j2]+2*dp0[j1])/3));
                }
            }
            swap(dp1,dp0);
        }
        for(int i=(1<<n);i>=0;i--){
            if((__int128)dp0[i]*y<=(__int128)x*b){
                printf("%.10lf\n",1.0*i/(1<<n));
                // cout<<<<'\n';
                return;
            }
        }
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}