// https://ac.nowcoder.com/acm/contest/117503/J
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pb push_back
const int N=1e5,mod=998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int a,b,c,x;
        cin>>a>>b>>c>>x; 
        if(x==c||2*b-a!=0&&(x-c)%(2*b-a)==0||x+c+b==0||2*b-a!=0&&(x+c+b-a)%(2*b-a)==0&&(x+c+b-a)/(2*b-a)>0||x+c-b==0||a-2*b!=0&&(x+c-b)%(a-2*b)==0&&(x+c-b)/(a-2*b)>0){
            cout<<"Yes\n";
        }else cout<<"No\n";

    };

    int t;
    for(cin >> t; t--; )
    solve();
    return 0;
}