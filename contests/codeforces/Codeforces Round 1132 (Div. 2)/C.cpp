#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005;
// 3. 欧拉筛
vector<int> pri;
bool not_prime[N];
void Eular_Sleve(int n) {
  for (int i = 2; i <= n; ++i) {
    if (!not_prime[i]) {
      pri.push_back(i);
    }
    for (int pri_j : pri) {
      if (i * pri_j > n) break;
      not_prime[i * pri_j] = true;
      if (i % pri_j == 0) {
        // i % pri_j == 0
        // 换言之，i 之前被 pri_j 筛过了
        // 由于 pri 里面质数是从小到大的，所以 i 乘上其他的质数的结果一定会被
        // pri_j 的倍数筛掉，就不需要在这里先筛一次，所以这里直接 break
        // 掉就好了
        break;
      }
    }
  }
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    Eular_Sleve(200005);
    auto solve=[&](){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++){
            cout<<*upper_bound(pri.begin(),pri.end(),a[i])<<" ";
        }
        cout<<"\n";
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}