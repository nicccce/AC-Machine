#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    auto solve=[&](){
        int a[6][6]={
            {11,8,3,27,24,1},
            {2,21,16,35,17,4},
            {9,29,20,30,5,10},
            {36,33,13,6,23,7},
            {31,14,15,28,12,25},
            {34,19,18,37,22,39}
        };
        vector<int> b;
        for(int i=0;i<6;i++)for(int j=0;j<5;j++)
            if((a[i][j]+a[i][j+1])%2)
                b.push_back((1LL<<(i*6+j))|(1LL<<(i*6+j+1)));
        for(int i=0;i<5;i++)for(int j=0;j<6;j++)
            if((a[i][j]+a[i+1][j])%2)
                b.push_back((1LL<<(i*6+j))|(1LL<<((i+1)*6+j)));
        int ans=0,n=b.size();
        for(int i=0;i<n;i++)for(int j=i+1;j<n;j++){
            if(b[i]&b[j])continue;
            for(int k=j+1;k<n;k++)
                if(!(b[i]&b[k])&&!(b[j]&b[k]))ans++;
        }
        cout<<ans<<endl;
    };
    solve();
}