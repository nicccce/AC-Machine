// https://codeforces.com/gym/105632/problem/B
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n;
        cin>>n;
        vector<vector<int>> a(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<2*i+1;j++){
                a[i].push_back(0);
                cin>>a[i][j];
            }
        }
        struct dice
        {
            int i,j,ang,step;
        };
        int x,y;
        cin>>x>>y;
        vector<vector<bool>> vis(n,vector<bool>(2*n+1));
        queue<dice> q;
        q.push(dice{0,0,2,0});
        vis[0][0]=1;
        while (q.size())
        {
            auto d=q.front();q.pop();
            int i=d.i,j=d.j,ang=d.ang,step=d.step;
            if(i==x-1 && j==y-1){
                cout<<step<<'\n';
                return;
            }
            // cout<<i<<' '<<j<<' '<<ang<<'\n';
            if(j%2){
                if(i>0&&!vis[d.i-1][d.j-1]&&a[d.i-1][d.j-1]==d.ang){
                    vis[d.i-1][d.j-1]=1;
                    q.push(dice{d.i-1,d.j-1,a[i][j],d.step+1});
                }
                int tmp,ttmp;
                if(a[i][j]==1&&ang==2){
                    tmp=4,ttmp=3;
                }
                if(a[i][j]==1&&ang==3){
                    tmp=2,ttmp=4;
                }
                if(a[i][j]==1&&ang==4){
                    tmp=3,ttmp=2;
                }
                if(a[i][j]==2&&ang==1){
                    tmp=3,ttmp=4;
                }
                if(a[i][j]==2&&ang==3){
                    tmp=4,ttmp=1;
                }
                if(a[i][j]==2&&ang==4){
                    tmp=1,ttmp=3;
                }
                if(a[i][j]==3&&ang==1){
                    tmp=4,ttmp=2;
                }
                if(a[i][j]==3&&ang==2){
                    tmp=1,ttmp=4;
                }
                if(a[i][j]==3&&ang==4){
                    tmp=2,ttmp=1;
                }
                if(a[i][j]==4&&ang==1){
                    tmp=2,ttmp=3;
                }
                if(a[i][j]==4&&ang==2){
                    tmp=3,ttmp=1;
                }
                if(a[i][j]==4&&ang==3){
                    tmp=1,ttmp=2;
                }
                // int tmp=(ang)%4+1;
                // if(tmp==a[i][j])tmp=tmp%4+1;
                // int ttmp=tmp%4+1;
                // if(ttmp==a[i][j])ttmp=ttmp%4+1;
                // int tttmp=ttmp%4+1;
                // // if(tttmp==a[i][j])tttmp=tttmp%4+1;
                // cout<<tmp<<ttmp<<tttmp<<'\n';
                if(j>0&&!vis[d.i][d.j-1]&&a[i][j-1]==tmp){
                    vis[i][j-1]=1;
                    q.push(dice{i,j-1,ttmp,step+1});
                }if(j<2*i&&!vis[i][j+1]&&a[i][j+1]==ttmp){
                    vis[i][j+1]=1;
                    q.push(dice{i,j+1,tmp,step+1});
                }
            }else{
                if(i<n-1&&!vis[i+1][j+1]&&a[i+1][j+1]==d.ang){
                    vis[i+1][j+1]=1;
                    q.push(dice{i+1,j+1,a[i][j],d.step+1});
                }
                
                int tmp,ttmp;
                if(a[i][j]==1&&ang==2){
                    tmp=4,ttmp=3;
                }
                if(a[i][j]==1&&ang==3){
                    tmp=2,ttmp=4;
                }
                if(a[i][j]==1&&ang==4){
                    tmp=3,ttmp=2;
                }
                if(a[i][j]==2&&ang==1){
                    tmp=3,ttmp=4;
                }
                if(a[i][j]==2&&ang==3){
                    tmp=4,ttmp=1;
                }
                if(a[i][j]==2&&ang==4){
                    tmp=1,ttmp=3;
                }
                if(a[i][j]==3&&ang==1){
                    tmp=4,ttmp=2;
                }
                if(a[i][j]==3&&ang==2){
                    tmp=1,ttmp=4;
                }
                if(a[i][j]==3&&ang==4){
                    tmp=2,ttmp=1;
                }
                if(a[i][j]==4&&ang==1){
                    tmp=2,ttmp=3;
                }
                if(a[i][j]==4&&ang==2){
                    tmp=3,ttmp=1;
                }
                if(a[i][j]==4&&ang==3){
                    tmp=1,ttmp=2;
                }
                // int tmp=(ang)%4+1;
                // if(tmp==a[i][j])tmp=tmp%4+1;
                // int ttmp=tmp%4+1;
                // if(ttmp==a[i][j])ttmp=ttmp%4+1;
                // int tttmp=ttmp%4+1;
                // if(tttmp==a[i][j])tttmp=tttmp%4+1;
                // cout<<tmp<<ttmp<<'\n';
                if(j<2*i&&!vis[i][j+1]&&a[i][j+1]==tmp){
                    vis[i][j+1]=1;
                    q.push(dice{i,j+1,ttmp,step+1});
                }if(j>0&&!vis[i][j-1]&&a[i][j-1]==ttmp){
                    vis[i][j-1]=1;
                    q.push(dice{i,j-1,tmp,step+1});
                }
            }
        }
        cout<<"-1\n";
        
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}