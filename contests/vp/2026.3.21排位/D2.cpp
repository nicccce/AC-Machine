#include <bits/stdc++.h>
using namespace std;

#define int long long
signed main() {
    auto solve=[&](){
        int h, c, t;
        cin>>h>>c>>t;
        if (h==t) {
            cout<<1<<'\n';
            return;
        }
        if (2*t<=h+c) {
            cout<<2<<'\n';
            return;
        }
        int x=(h-t)/(2*t-h-c);
        auto get_num = [&](int cur_x) {
            return cur_x * (h + c) + h;
        };
        auto get_den = [&](int cur_x) {
            return 2 * cur_x + 1;
        };
        int x1 = x,x2 = x + 1;
        int num1=abs(get_num(x1)-t*get_den(x1));
        int den1=get_den(x1);
        int num2 = abs(get_num(x2) - t * get_den(x2));
        int den2 = get_den(x2);
        if (num1 * den2 <= num2 * den1) {
            cout << 2 * x1 + 1 << '\n';
        } else {
            cout << 2 * x2 + 1 << '\n';
        }
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}