// https://codeforces.com/contests/2163/problem/A
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N = 1e5, mod = 998244353;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    struct led{
        int l0,l1,l2,l3,l4,l5,l6;
        int* p[7]={&l0,&l1,&l2,&l3,&l4,&l5,&l6};
    };
    auto solve = [&]() {
        int n,k;
        cin>>n>>k;
        vector<string> inputs(7);
        for(int i=0;i<7;i++){
            cin>>inputs[i];
        }
        vector<led> a(n+1);
        for(int i=1;i<=n;i++){
            a[i].l0=inputs[0][(i-1)*5+1];
            a[i].l1=inputs[1][(i-1)*5];
            a[i].l2=inputs[1][(i-1)*5+3];
            a[i].l3=inputs[3][(i-1)*5+1];
            a[i].l4=inputs[4][(i-1)*5];
            a[i].l5=inputs[4][(i-1)*5+3];
            a[i].l6=inputs[6][(i-1)*5+1];
            for(int j=0;j<7;j++){
                if(*a[i].p[j]=='w'){
                    *a[i].p[j]=2;
                }else{
                    *a[i].p[j]-='0';
                }
            }
        }
        for(int i=0;i<7;i++){
            
        }
    };

    int t;
    for (cin >> t; t--;)
        solve();
    return 0;
}