#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int a,b;
        cin>>a>>b;
        int ans=0;
        auto is_leap = [&](int year) {
            return (year%4==0 && year%100!=0) || (year%400==0);
        };
        auto valid_date = [&](int y,int m,int d) {
            if(m<1 || m>12) return false;
            if(d<1) return false;
            int days_in_month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
            if(m==2 && is_leap(y)) {
                if(d>29) return false;
            }
            else {
                if(d>days_in_month[m]) return false;
            }
            return true;
        };
        for(int date=a;date<=b;date++) {
            int Y = date/10000;
            int M = (date/100)%100;
            int D = date%100;
            if(!valid_date(Y,M,D)) continue;
            string s = to_string(date);
            string t = s;
            reverse(t.begin(),t.end());
            if(s==t) ans++;
        }
        cout<<ans<<"\n";
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}