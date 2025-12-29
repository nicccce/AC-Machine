#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int a,b,c;
        cin>>a>>b>>c;
        if(a+b<=c||a+c<=b||b+c<=a)cout<<"Not a triangle";
        else if(a==b&&b==c)cout<<"Equilateral triangle";
        else if(a==b||b==c||a==c)cout<<"Isosceles triangle";
        else cout<<"Ordinary triangle";
        cout<<'!';
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}