#include <bits/stdc++.h>
using namespace std;
#define  int long long

signed main(){
    auto solve = [&](){
        string s;
        cin>>s;
        bool flag=0;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1])flag=1;
        }
        cout<<(int)s.length()-2+flag<<"\n";
    };
    int t;
    for(cin>>t;t;t--)
    solve();
}