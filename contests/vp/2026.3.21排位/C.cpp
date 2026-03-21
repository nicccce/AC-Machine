#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[1000005];
int n, m;

bool check(int k) {  // 检查可行性，k 为锯片高度
  long long sum = 0;
  for (int i = 1; i <= n; i++)       // 检查每一棵树
    if (a[i] > k)                    // 如果树高于锯片高度
      sum += (long long)(a[i] - k);  // 累加树木长度
  return sum >= m;                   // 如果满足最少长度代表可行
}

int find() {
  int l = 1, r = 1e9 + 1;   // 因为是左闭右开的，所以 10^9 要加 1
  while (l + 1 < r) {       // 如果两点不相邻
    int mid = (l + r) / 2;  // 取中间值
    if (check(mid))         // 如果可行
      l = mid;              // 升高锯片高度
    else
      r = mid;  // 否则降低锯片高度
  }
  return l;  // 返回左边值
}


signed main(){

    auto solve=[&](){
        int n;
        cin>>n;
        struct qj
        {
            int r,l,ind;
        };
        vector<qj> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i].l>>a[i].r;
            a[i].ind=i;
        }
        sort(a.begin(),a.end(),[&](qj x,qj y){
            if(x.r==y.r)return x.l<y.l;
            return x.r<y.r;
        });
        vector<int> mmin(n);
        mmin[n-1]=a[n-1].l;
        for(int i=n-2;i>0;i--){
            // cout<<111<<endl;
            mmin[i]=min(a[i].l,mmin[i+1]);
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(i==n-1){
                cout<<-1<<'\n';
                return;
            }
            ans[a[i].ind]=1;
            if(a[i].r<mmin[i+1]){
                break;
            }
        }
        auto check = [&](int x){
            for(int i=0;i<n;i++){
                if(a[i].r<=x||a[i].l>x){
                    continue;
                }
                return 0;
            }
            return 1;
        };
        for(int i=0;i<n;i++){
            cout<<ans[i]+1<<' ';
        }cout<<'\n';
    };
    int t;
    for(cin>>t;t;t--)
    solve();

}