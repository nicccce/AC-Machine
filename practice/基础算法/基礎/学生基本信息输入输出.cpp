#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        string i;
        double a, b, c;
        while (1){
            char ch = getchar();
            if(ch==';') break;
            i.push_back(ch);
        }
        #undef int
        scanf("%lf,%lf,%lf",&a,&b,&c);
        // cout<<"Debug: a is "<<a<<".\n";
        a=1.0*(int(a*100+0.5))/100;
        b=1.0*(int(b*100+0.5))/100;
        c=1.0*(int(c*100+0.5))/100;
        // printf("The each subject score of No. %s is %.2f, %.2f, %.2f.\n",i.c_str(),a,b,c);
        cout<<"The each subject score of No. "<<i<<" is "<<fixed<<setprecision(2)<<a<<", "<<b<<", "<<c<<".\n";
        
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}