// https://qoj.ac/contest/2606/problem/14943
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N = 1e5, mod = 998244353;
signed main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);
    struct led{
        vector<int> p{0,0,0,0,0,0,0};
        // int p[7];
        // int l0,l1,l2,l3,l4,l5,l6;
        // int* p[7]={&l0,&l1,&l2,&l3,&l4,&l5,&l6};
        vector<vector<int>> nums{
            {1,1,1,0,1,1,1},
            {0,0,1,0,0,1,0},
            {1,0,1,1,1,0,1},
            {1,0,1,1,0,1,1},
            {0,1,1,1,0,1,0},
            {1,1,0,1,0,1,1},
            {1,1,0,1,1,1,1},
            {1,0,1,0,0,1,0},
            {1,1,1,1,1,1,1},
            {1,1,1,1,0,1,1}
        };
        vector<int> checknums(){
            vector<int> cnt(4);
            cnt[0]=1;
            cnt[1]=1;
            cnt[2]=1;
            for(int i=0;i<7;i++){
                if(p[i]==1){
                    cnt[0]-=1;
                    cnt[1]-=1;
                    break;
                }
            }
            for(int i=0;i<7;i++){
                if(nums[0][i]==0&&p[i]==1){
                    cnt[2]-=1;
                    break;
                }
                if(nums[0][i]==1&&p[i]==0){
                    cnt[2]-=1;
                    break;
                }
            }
            for(int i=1;i<=9;i++){
                cnt[3]+=1;
                for(int j=0;j<7;j++){
                    if(nums[i][j]==0&&p[j]==1){
                        cnt[3]-=1;
                        break;
                    }
                    if(nums[i][j]==1&&p[j]==0){
                        cnt[3]-=1;
                        break;
                    }
                }
            }
            cnt[2]+=cnt[2];
            cnt[0]*=cnt[2];
            cnt[1]*=cnt[3];
            return cnt;
        }
    };
    auto solve = [&]() {
        int n,k;
        cin>>n>>k;
        vector<string> inputs(7);
        for(int i=0;i<7;i++){
            string s;
            cin>>s;
            inputs[i]=s;
            // cin>>inputs[i];
            
            // cout<<i<<s<<'\n';
        }
        vector<led> a(n+1);
        int ans = 0,anscnt=0;
        for(int i=1;i<=n;i++){
            a[i].p[0]=inputs[0][(i-1)*5+1];
            a[i].p[1]=inputs[1][(i-1)*5];
            a[i].p[2]=inputs[1][(i-1)*5+3];
            a[i].p[3]=inputs[3][(i-1)*5+1];
            a[i].p[4]=inputs[4][(i-1)*5];
            a[i].p[5]=inputs[4][(i-1)*5+3];
            a[i].p[6]=inputs[6][(i-1)*5+1];
            for(int j=0;j<7;j++){
                if(a[i].p[j]=='W'){
                    a[i].p[j]=2;
                }else{
                    a[i].p[j]-='0';
                }
                // cout<<*a[i].p[j];
            }
            // cout<<'\n';
        }
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(k+1,vector<int>(3,0))),dpcnt(n+1,vector<vector<int>>(k+1,vector<int>(3,0)));
        dp[0][0][0]=dpcnt[0][0][0]=1;
        for(int i=1;i<=n;i++){
            vector<vector<int>> cnt(8,vector<int>(4,0)),samecnt(8,vector<int>(4,0));
            for(int g=0;g<(1ll<<7);g++){
                led nowled;
                nowled.p = vector<int>(a[i].p);
                int cntseg=0;
                for(int b=0;b<7;b++){
                    if((g&(1ll<<b))!=0){
                        cntseg++;
                        nowled.p[b]=2;
                    }
                }
                auto nums = nowled.checknums();
                for(int j=0;j<4;j++){
                    if(cnt[cntseg][j]<nums[j]){
                        cnt[cntseg][j]=nums[j];
                        samecnt[cntseg][j]=1;
                    }else if(cnt[cntseg][j]==nums[j]){
                        samecnt[cntseg][j]+=1;
                    }
                }
            }
            // cout<<cnt[0][0]<<cnt[0][1]<<cnt[0][2]<<'\n';
            // cout<<cnt[1][0]<<cnt[1][1]<<cnt[1][2]<<'\n';
            // cout<<cnt[2][0]<<cnt[2][1]<<cnt[2][2]<<'\n';
            // cout<<samecnt[0][0]<<samecnt[0][1]<<samecnt[0][2]<<'\n';
            // cout<<samecnt[1][0]<<samecnt[1][1]<<samecnt[1][2]<<'\n';
            // cout<<samecnt[2][0]<<samecnt[2][1]<<samecnt[2][2]<<'\n';
            for(int j=0;j<=k;j++){
                for(int jj=0;jj<=min(7ll,j);jj++){
                    int tmp = dp[i-1][j-jj][0]*cnt[jj][0];
                    // cout<<"tmp"<<tmp<<'\n';
                    int tmpcnt = dpcnt[i-1][j-jj][0]*samecnt[jj][0];
                    if(dp[i][j][0]<tmp){
                        dp[i][j][0]=tmp;
                        dpcnt[i][j][0]=tmpcnt;
                    }else if(dp[i][j][0]==tmp){
                        dpcnt[i][j][0]+=tmpcnt;
                    }//过了吗过了吗，哈基米南北绿豆
                    //在五排，别闹 6666666666666666666666666666666666666666666666666666666666666666666666666
                    tmp = dp[i-1][j-jj][0]*cnt[jj][2];
                    tmpcnt = dpcnt[i-1][j-jj][0]*samecnt[jj][2];
                    if(tmp<dp[i-1][j-jj][1]*cnt[jj][1]){
                        tmp=dp[i-1][j-jj][1]*cnt[jj][1];
                        tmpcnt=dpcnt[i-1][j-jj][1]*samecnt[jj][1];
                    }else if(tmp==dp[i-1][j-jj][1]*cnt[jj][1]){
                        tmpcnt+=dpcnt[i-1][j-jj][1]*samecnt[jj][1];
                    }
                    // cout<<"tmp"<<tmp<<'\n';
                    if(i==n){
                        // tmp=dp[i-1][j-jj][0]*cnt[jj][1]+dp[i-1][j-jj][1]*cnt[jj][1];
                        // tmpcnt=dpcnt[i-1][j-jj][0]*samecnt[jj][1]+dpcnt[i-1][j-jj][1]*samecnt[jj][1];
                        tmp = dp[i-1][j-jj][0]*cnt[jj][1];
                        tmpcnt = dpcnt[i-1][j-jj][0]*samecnt[jj][1];
                        if(tmp<dp[i-1][j-jj][1]*cnt[jj][1]){
                            tmp=dp[i-1][j-jj][1]*cnt[jj][1];
                            tmpcnt=dpcnt[i-1][j-jj][1]*samecnt[jj][1];
                        }else if(tmp==dp[i-1][j-jj][1]*cnt[jj][1]){
                            tmpcnt+=dpcnt[i-1][j-jj][1]*samecnt[jj][1];
                        }
                    }
                    if(dp[i][j][1]<tmp){
                        dp[i][j][1]=tmp;
                        dpcnt[i][j][1]=tmpcnt;
                    }else if(dp[i][j][1]==tmp){
                        dpcnt[i][j][1]+=tmpcnt;
                    }
                    if(i==n){
                        if(dp[i][j][1] > ans){
                            ans = dp[i][j][1];
                        }
                    }
                }
            }
        }
        for(int i=0;i<=k;i++){
            if(dp[n][i][1]==ans){
                anscnt+=dpcnt[n][i][1];
            }
        }
        cout<<ans<<' '<<anscnt<<'\n';
    };

    int t;
    for (cin >> t;t;t--)
        solve();
    return 0;
}
/*

2
3 2
.00...00...00.
0..0.0..0.0..1
0..0.0..0.0..1
.00...00...00.
0..W.0..0.0..1
0..W.0..0.0..1
.00...00...00.
9 62
.WW...WW...WW...WW...WW...WW...WW...WW...WW.
W..W.W..W.W..W.W..W.W..W.W..W.W..W.W..W.W..W
W..W.W..W.W..W.W..W.W..W.W..W.W..W.W..W.W..W
.WW...WW...WW...WW...WW...WW...WW...WW...WW.
W..W.W..W.W..W.W..W.W..W.W..W.W..W.W..W.W..W
W..W.W..W.W..W.W..W.W..W.W..W.W..W.W..W.W..W
.WW...WW...WW...WW...WW...WW...WW...WW...WW.

*/