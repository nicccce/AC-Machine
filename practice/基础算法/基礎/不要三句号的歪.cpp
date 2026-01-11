#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        string s;
        cin>>s;
        // 解析字符串
        int pos1 = s.find(',');
        int pos2 = s.find("...", pos1 + 1);
        int pos3 = s.find(',', pos2 + 3);
        int a = stoll(s.substr(0, pos1));
        int b = stoll(s.substr(pos1 + 1, pos2 - pos1 - 1));
        int c = stoll(s.substr(pos3 + 1));
        // 计算省略的数字数量
        int omitted_count = c - b - 1;
        cout<<omitted_count<<"\n";
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}