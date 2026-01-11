#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n;
        cin>>n;
        vector<int> a(n+1);
        for(int i=n;i>=0;i--) {
            cin>>a[i];
        }
        stringstream ss;
        bool first = true;
        for(int i=n;i>=0;i--) {
            if(a[i]==0) continue;
            if(first) {
                // 最高次项
                if(a[i]<0) ss<<"-";
                if(abs(a[i])!=1 || i==0) ss<<abs(a[i]);
                if(i>=2) ss<<"x^"<<i;
                else if(i==1) ss<<"x";
                first = false;
            }
            else {
                // 非最高次项
                if(a[i]>0) ss<<"+";
                else ss<<"-";
                if(abs(a[i])!=1 || i==0) ss<<abs(a[i]);
                if(i>=2) ss<<"x^"<<i;
                else if(i==1) ss<<"x";
            }
        }
        cout<<ss.str()<<"\n";
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}