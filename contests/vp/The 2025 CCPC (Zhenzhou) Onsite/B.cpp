// https://qoj.ac/contest/2643/problem/15302
#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9+7;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    struct cube{int x,y,z,idx,idy,idz;};
    auto solve = [&]() {
        int l,w,h,p,q,r,n;
        cin>>l>>w>>h>>p>>q>>r>>n;
        vector<cube> a(n);
        for(int i=0;i<n;i++)cin>>a[i].x>>a[i].y>>a[i].z;
        int ans=1,cnt=0,ind=0;
        if(n%((p+1)*(q+1)*(r+1))){
            cout<<0<<'\n';
            return;
        }
        sort(a.begin(),a.end(),[&](cube x,cube y){
            return x.x<y.x;
        });
        for(int i=1;i<n;i++){
            if(i%(n/(p+1))==0)ans=(ans*(a[i].x-a[i-1].x))%mod,cnt++;
            a[i].idx=cnt;
        }sort(a.begin(),a.end(),[&](cube x,cube y){
            return x.y<y.y;
        });
        vector<int>c(p+1);
        cnt=0;
        for(int i=0;i<n;i++){
            c[a[i].idx]++;
            if(c[a[i].idx]==(ind+1)*(n/(p+1)/(q+1))+1){
                if(cnt!=p+1)ans=0;
                else cnt=0,ind+=1,ans=(ans*(a[i].y-a[i-1].y))%mod;
            }if(c[a[i].idx]==(ind+1)*(n/(p+1)/(q+1)))cnt++;
            a[i].idy=ind;
        }sort(a.begin(),a.end(),[&](cube x,cube y){
            return x.z<y.z;
        });
        c=vector<int>(p+1);
        cnt=0,ind=0;
        for(int i=0;i<n;i++){
            c[a[i].idx]++;
            if(c[a[i].idx]==(ind+1)*(n/(p+1)/(r+1))+1){
                if(cnt!=p+1)ans=0;
                else cnt=0,ind+=1,ans=(ans*(a[i].z-a[i-1].z))%mod;
            }if(c[a[i].idx]==(ind+1)*(n/(p+1)/(r+1)))cnt++;
            a[i].idz=ind;
        }sort(a.begin(),a.end(),[&](cube x,cube y){
            return array<int,3>{x.idx,x.idy,x.idz}<array<int,3>{y.idx,y.idy,y.idz};
        });cnt=1;
        for(int i=1;i<n;i++){
            if(a[i].idz!=a[i-1].idz){
                if(cnt!=n/((p+1)*(q+1)*(r+1)))ans=0;
                cnt=0;
            }cnt++;
        }
        cout<<ans<<'\n';
    };
    solve();
    return 0;
}