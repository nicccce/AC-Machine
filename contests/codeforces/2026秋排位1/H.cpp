#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;

struct tr{
    int i,j,x;
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    
    auto solve=[&](){
        int n,k;cin>>n>>k;
        vector<int>a(n+1);
        for(int i=1;i<=n;i++)cin>>a[i];
        
        int u=-1,v=-1;
        map<int,int>S;
        for(int i=1;i<=n;i++){
            if(S.count(k-a[i])){u=S[k-a[i]];v=i;break;}
            S[a[i]]=i;
        }
        
        if(u==-1){
            bool f=1;
            for(int i=1;i<n;i++)if(a[i]>a[i+1])f=0;
            cout<<(f?0:-1)<<"\n";
            return;
        }
        
        vector<tr>ans;
        auto op=[&](int i,int j,int ti,int tj){
            int x=a[i]-ti;a[i]-=x;a[j]+=x;
            ans.push_back({i,j,x});
        };
        
        if(a[u]!=0&&a[u]!=k)op(u,v,0,k);
        if(a[u]==k)swap(u,v);
        
        if(u==n){op(u,v,k,0);swap(u,v);}
        if(u!=1){
            if(v==1){op(v,u,0,k);swap(u,v);}
            else{int x=a[1];op(v,u,k-x,x);op(v,1,k,0);u=1;} 
        }
        if(v!=n){
            int x=a[n];op(v,u,x,k-x);op(n,u,k,0);v=n;
        }
        
        vector<int>b=a;sort(b.begin()+1,b.end());
        map<int,set<int>>P;
        for(int i=2;i<n;i++)P[a[i]].insert(i);
        
        int U=1;
        for(int i=2;i<n;i++){
            if(a[i]==b[i]){P[a[i]].erase(i);continue;}
            int j=-1;
            for(int c:P[b[i]]){
                if(c!=U){ 
                    j=c;
                    break;
                }
            }
            
            int x=a[i],y=a[j];
            op(n,U,k-x,x);
            op(n,i,k-y,y);
            op(n,j,k,0);
            
            P[y].erase(j);
            P[x].erase(i);
            P[x].insert(U);
            U=j;
        }
        
        cout<<ans.size()<<"\n";
        for(auto&i:ans)
            cout<<i.i<<" "<<i.j<<" "<<i.x<<"\n";
    };
    
    int t;
    for(cin>>t;t;t--) solve();
    return 0;
}