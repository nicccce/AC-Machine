#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=400010;
int group[maxn];
inline int findroot(int x) {
    if (x == group[x])
        return x;
    return group[x] = findroot(group[x]);
}
inline void unite(int a, int b) {
    int ra = findroot(a);
    int rb = findroot(b);
    if (ra != rb)
        group[ra] = rb;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    auto solve = [&]() {
        int n,d;cin>>n>>d;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }sort(a.begin()+1,a.end());
        a.erase(unique(a.begin()+1,a.end()),a.end());
        n=a.size()-1;
        if(a[n]-a[1]<d){
            cout<<1<<"\n";
            return;
        }
        if(a[n]-a[1]<2*d){
            cout<<2<<"\n";
            return;
        }
        for (int i = 1; i <= 2*n; i++)
            group[i] = i;
        int l,r;
        l=1,r=1;
        vector<int> rl(n+1),rr(n+1),ll(n+1),lr(n+1);
        for(int i=1;i<=n;i++){
            while(l<=n&&a[l]-a[i]<d)l++;
            while(r<=n&&a[r]-a[i]<2*d)r++;
            rl[i]=l,rr[i]=r;
        }
        l=1,r=1;
        for(int i=1;i<=n;i++){
            while(l<=i&&a[i]-a[r]>=2*d)l++;
            while(r<=i&&a[i]-a[r]>d)r++;
            rl[i]=l,rr[i]=r;
        }
        vector<int> vis(n+1);
        
        cout<<2<<'\n';
    };
    int t;
    for (cin >> t; t; t--) 
    solve();
    return 0;
}