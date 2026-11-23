#include<bits/stdc++.h>
using namespace std;
#define int long long
using i128=__int128;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto pw=[&](int x,int y){
        int r=1;
        for(int i=0;i<y;i++)r*=x;
        return r;
    };
    auto phi=[&](int p,int c){
        if(!c)return 1ll;
        return (p-1)*pw(p,c-1);
    };
    auto solve=[&](){
        int k;cin>>k;
        vector<pair<int,int>>a(k);
        for(int i=0;i<k;i++)cin>>a[i].first>>a[i].second;
        sort(a.begin(),a.end());
        vector<int>pre(k+1,1),suf(k+1,1);
        for(int i=0;i<k;i++)pre[i+1]=pre[i]*phi(a[i].first,a[i].second);
        for(int i=k-1;i>=0;i--)suf[i]=suf[i+1]*phi(a[i].first,a[i].second);
        int ans=suf[0];
        for(int i=0;i<k;i++)ans+=pre[i]*phi(a[i].first,a[i].second-1)*suf[i+1];
        int n1=1;
        for(int l=0;l<k;l++){
            if(n1<a[l].first){
                int mid=1,dm=1;
                for(int m=l;m<k;m++){
                    int pm=a[m].first,em=a[m].second,g=mid;
                    for(int am=1;am<=em;am++){
                        g*=pm;
                        if(l==m&&am==1)continue;
                        if(am<em&&pm<=mid)continue;
                        if(m<k-1&&g>=a[m+1].first)break;
                        bool ok=1;
                        if(l>0&&l<m){
                            int r=dm*(am+1);
                            if(r>=64)ok=0;
                            else{
                                i128 t=1;
                                for(int j=1;j<r;j++){
                                    t*=n1;
                                    if(t>=g){ok=0;break;}
                                }
                            }
                            if(ok){
                                vector<int>d={1};
                                d.reserve(r);
                                for(int i=l;i<=m;i++){
                                    int c=(i==m?am:a[i].second),sz=d.size(),q=1;
                                    for(int x=1;x<=c;x++){
                                        q*=a[i].first;
                                        for(int j=0;j<sz;j++)d.push_back(d[j]*q);
                                    }
                                }
                                sort(d.begin(),d.end());
                                for(int j=1;j<r;j++){
                                    if((i128)n1*d[j-1]>=d[j]){ok=0;break;}
                                }
                            }
                        }
                        if(ok)ans+=pre[l]*phi(pm,em-am)*suf[m+1];
                    }
                    mid*=pw(pm,em);
                    dm*=em+1;
                }
            }
            n1*=pw(a[l].first,a[l].second);
        }
        cout<<ans<<'\n';
    };
    int t;
    for(cin>>t;t;t--)solve();
    return 0;
}