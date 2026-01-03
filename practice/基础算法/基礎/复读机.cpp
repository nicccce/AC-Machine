#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        string s;
        while(cin>>s) {
            if(s.find(".")!=string::npos) {
                printf("%.1f\n",stof(s));
            }else{  
                cout<<s<<"\n";
            }
        }
        
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}