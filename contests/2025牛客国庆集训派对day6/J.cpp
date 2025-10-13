#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
// 我怎么要没钱了，怎么办，没钱了没钱了没钱了没钱了没钱了没钱了没钱了没钱了
// 唉，这几把程序怎么这么难写
// 不会写了，不如写点注释
// 这注释真有用吧
// 怎么有人vscode都没打开
// 写个damn啊
// 无敌了，还在写注释
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int tmp;
    auto solve = [&]() {
        int n;
        cin>>n;
        vector<int> a(n),cnt(3),cntpir(3);
        for(int i=0;i<n;i++){
            cin>>a[i];
            cnt[a[i]]++;
        }
        for(int i=1;i<=n;i++){
            if(a[i%n]==(a[i-1]+1)%3){
                cntpir[a[i]]++;
            }
        }
    };
    
    int t;
    for(cin >> t; t--;)
    solve();
    return 0;
}