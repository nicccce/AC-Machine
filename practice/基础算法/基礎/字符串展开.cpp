#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int p1,p2,p3;
        cin>>p1>>p2>>p3;
        string s;
        cin>>s;
        string ans;
        int n = s.size();
        for(int i=0;i<n;i++) {
            if(s[i]=='-') {
                if(i==0 || i==n-1) {
                    ans += '-';
                    continue;
                }
                char left = s[i-1];
                char right = s[i+1];
                if((isdigit(left) && isdigit(right)) || (islower(left) && islower(right))) {
                    if(right <= left) {
                        ans += '-';
                        continue;
                    }
                    else if(right == left + 1) {
                        // 直接删除减号
                        continue;
                    }
                    else {
                        // 需要展开
                        string fill_chars;
                        for(char c=left+1;c<right;c++) {
                            fill_chars += c;
                        }
                        // 根据p1处理填充字符
                        if(p1 == 3) {
                            for(int j=0;j<fill_chars.size();j++) {
                                fill_chars[j] = '*';
                            }
                        }
                        else if(p1 == 2) {
                            for(int j=0;j<fill_chars.size();j++) {
                                if(islower(fill_chars[j])) {
                                    fill_chars[j] = toupper(fill_chars[j]);
                                }
                            }
                        }
                        // 根据p3处理顺序
                        if(p3 == 2) {
                            reverse(fill_chars.begin(), fill_chars.end());
                        }
                        // 根据p2处理重复次数
                        string expanded_part;
                        for(char c : fill_chars) {
                            for(int j=0;j<p2;j++) {
                                expanded_part += c;
                            }
                        }
                        ans += expanded_part;
                    }
                }
                else {
                    ans += '-';
                }
            }
            else {
                ans += s[i];
            }
        }
        cout<<ans<<"\n";
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}