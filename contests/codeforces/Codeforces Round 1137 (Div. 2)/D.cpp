#include<bits/stdc++.h>
using namespace std;
#define int long long
#define lowbit(i) i & (-i)
struct Fenwick{
    int n;
    vector<int> tree;
    Fenwick(int sz): n(sz), tree(sz+1, 0) {}
    void upd(int pos, int x){
        for(int i=pos; i<=n; i+=lowbit(i))
            tree[i] = (tree[i]+x);
    }
    int summ(int pos){
        int res = 0;
        for(int i=pos; i>0; i-=lowbit(i))
            res = (res+tree[i]);
        return res;
    }
};
struct node{
    int val, pos;
    bool operator < (const node& other) const{
        if(val == other.val) return pos > other.pos;
        return val > other.val;
    }
};
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n;cin>>n;
        vector<int> a(n+1);
        vector<node> s(n+1);
        bool ok=1;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            s[i].val=s[i-1].val+a[i];
            s[i].pos=i;
            if(s[i].val<0)ok=0;
        }if(!ok){
            cout<<-1<<'\n';
            return;
        }
        sort(s.begin()+1, s.begin()+n+1);
        Fenwick fen(n+5);
        int ans = 0;
        for(int i=1; i<=n; i++){
            fen.upd(s[i].pos, 1);
            ans += fen.summ(s[i].pos-1);
        }
        cout<<ans<<'\n';
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}