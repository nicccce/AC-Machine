#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    auto solve = [&](){
        vector<string> g={"RRGRG","GRRRR","GGRRG","BRGRB","RBGGG"};
        while(1){
            vector<vector<bool>> v(5,vector<bool>(5,0));
            bool f=0;
            for(int i=0;i<5;i++)for(int j=0;j<3;j++)
                if(g[i][j]!='.'&&g[i][j]==g[i][j+1]&&g[i][j]==g[i][j+2])v[i][j]=v[i][j+1]=v[i][j+2]=1;
            for(int j=0;j<5;j++)for(int i=0;i<3;i++)
                if(g[i][j]!='.'&&g[i][j]==g[i+1][j]&&g[i][j]==g[i+2][j])v[i][j]=v[i+1][j]=v[i+2][j]=1;
            for(int i=0;i<5;i++)for(int j=0;j<5;j++)if(v[i][j])g[i][j]='.',f=1;
            if(!f)break;
            for(int j=0;j<5;j++){
                string s="";
                for(int i=4;i>=0;i--)if(g[i][j]!='.')s+=g[i][j];
                for(int i=0;i<5;i++)g[4-i][j]=(i<(int)s.size()?s[i]:'.');
            }
        }
        int res=0;
        for(int i=0;i<5;i++)for(int j=0;j<5;j++)if(g[i][j]!='.')res++;
        cout<<res<<endl;
    };
    solve();
}