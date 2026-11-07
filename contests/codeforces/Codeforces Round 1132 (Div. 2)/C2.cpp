#include<bits/stdc++.h>
using namespace std;
#define itn int
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
typedef long long ll;
const int maxn=200005;
#define P pair<ll, ll>   // first=to, second=weight
ll d[maxn];
int pre[maxn];           // 前驱节点，用于还原路径
bool vis[maxn];
vector<P> G[maxn];
const int inf = 0x3f3f3f3f;
const int nnn=1000;
void dij(int s,int a, int b) {
    priority_queue<P, vector<P>, greater<P>> pq;
    fill(d+a, d + b + 1, inf);
    fill(pre+a, pre + b + 1, -1);   // -1 表示无前驱（起点或不可达）
    fill(vis+a, vis+b+1,0);
    d[s] = 0;
    pq.emplace(P{0, s});
    while (pq.size()) {
        P p = pq.top(); pq.pop();
        int v = p.second;
        if (vis[v]) continue;
        vis[v] = 1;
        for (P e : G[v]) {
            if (vis[e.first]) continue;
            if (d[e.first] > d[v] + e.second) {
                d[e.first] = d[v] + e.second;
                pre[e.first] = v;               // 记录前驱
                pq.emplace(P{d[e.first], e.first});
            }
        }
    }
}

// 返回从 s 到 t 的最短路（节点序列）。不可达时返回空 vector
vector<int> getPath(int s, int t) {
    vector<int> path;
    if (d[t] == inf) return path;   // 不可达
    for (int cur = t; cur != -1; cur = pre[cur]) {
        path.push_back(cur);
        if (cur == s) break;
    }
    reverse(path.begin(), path.end());
    return path;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    Eular_Sleve(200005);
    auto solve=[&](){
        int a,b;
        cin>>a>>b;
        if(__gcd(a,b)==1){
          cout<<1<<"\n";
          cout<<b-a<<'\n';
          return;
        }
        int p=(upper_bound(pri.begin(),pri.end(),a)-pri.begin());
        for(itn i=0;i<10;i++){
          if(pri[p+i]>=b){
            break;
          }
          if(__gcd(pri[p+i],b)==1){
            cout<<2<<'\n';
            cout<<pri[p+i]-a<<' '<<b-pri[p+i]<<'\n';
            return;
          }
        }
        for(int i=a;i<=b;i++){
          G[i].clear();
        }
        for(int i=a;i<b;i++){
          for(int j=1;i+j<=b;j++){
            if(__gcd(i,j)!=1){
              continue;
            }
            G[i].push_back({i+j,1});
          }
        }
        dij(a,a,b);
        auto path = getPath(a,b);
        cout<<path.size()-1<<'\n';
        for(int i=1;i<path.size();i++){
          cout<<path[i]-path[i-1]<<' ';
        }
        cout<<'\n';
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}