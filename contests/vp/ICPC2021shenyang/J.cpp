#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
const int maxn = 4e5 + 10;
vector<int> g[maxn];


int cz[40] = {1000, 100, 10, 1, 1100, 110, 11, 1110, 111, 1111};

int cal(int u, int dt, int op){
    int ans = 0;
    for(int i = 10; i <= 10000; i *= 10){
        int x = u % i; x = x * 10 / i;
        int y = dt % i; y = y * 10 / i;
        if(op == 1) ans += i / 10 * ((x + y) % 10);
        else ans += i / 10 * ((x - y + 10) % 10);
    }
    return ans;
}

int dis[maxn], vis[maxn];
struct node{
    int u;
    ll dis;
    friend bool operator < (node x, node y){
        return x.dis > y.dis;
    }
};
priority_queue<node> qu;

void dijk(){
    qu.push({0, 0});
    memset(dis, 0x3f, sizeof(dis));
    dis[0] = 0;
    while(!qu.empty()){
        int u = qu.top().u;
        qu.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto v : g[u]){
            if(vis[v]) continue;
            if(dis[u] + 1 < dis[v]){
                dis[v] = dis[u] + 1;
                qu.push({v, dis[v]});
            }
        }
    }
}

void pre(){
    for(int i = 0; i <= 9999; i++){
        for(int j = 0; j <= 9; j++){
            int v = cal(i, cz[j], 1);
            g[i].push_back(v);
            v = cal(i, cz[j], 0);
            g[i].push_back(v);
        }
    }   

    dijk();

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    pre();

    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        y = cal(y, x, 0);
        // cout << y << " "; 
        cout << dis[y] << endl;
    }

	return 0;
}