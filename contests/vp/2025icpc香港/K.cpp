#include<bits/stdc++.h>
#define N 1000017
using namespace std;

int n,a[N],st[N],nxt[N],lst[N];

void solve(){
    cin >> n;
    for(int i = 1;i <= n;i += 1)cin >> a[i],a[i+n] = a[i],nxt[i] = 0;
    int top = 0;
    for(int i = 1;i < 2*n;i += 1){
        if(!top)st[++top] = i;
        else {
            while(top && a[st[top]] < a[i]){
                nxt[st[top]] = i;
                top--;
            }
            st[++top] = i;
        }
    }
    for(int i = 1;i <= n;i += 1){
        if(nxt[i] > n)nxt[i] -= n;
        //cout << nxt[i] << ' ';
    }
    //cout << '\n';
    int minn = a[1];
    for(int i = 1;i <= n;i += 1)minn = min(minn,a[i]),lst[i] = 0;
    vector<int>ans;
    for(int i = 1;i <= n;i += 1)
        if(minn == a[i])ans.push_back(i);
    while(ans.size() > 1){
        int c = 0,clen = 0;
        for(int i = 0;i < ans.size();i += 1){
            int u = ans[i];
            if(!nxt[u])continue;
            int v = nxt[u];
            int len = v-u;
            if(len < 0)len += n;
            if(!c)c = u,clen = len;
            if(len > clen)c = u,clen = len;
            else if(len == clen && a[v] < a[nxt[c]])c = u;
            //cout << "u,v,len: " << u << ' ' << v << ' ' << len << '\n';
        }
        if(!c)break;
        vector<int>tmp;
        for(int i = 0;i < ans.size();i += 1){
            int u = ans[i];
            if(!nxt[u])continue;
            int v = nxt[u];
            int len = v-u;
            if(len < 0)len += n;
            if(len == clen && a[v] == a[nxt[c]])lst[v] = u,tmp.push_back(v);
        }
        ans = tmp;
    }
    int x = ans[0];
    while(lst[x])x = lst[x];
    int maxn = a[x];
    //cout << "x:" << x << '\n';
    for(int i = x;i < x+n;i += 1)maxn = max(maxn,a[i]),cout << maxn << ' ';
    cout << '\n';
}

int main()
{
    int T;cin >> T;
    while(T--)solve();
    return 0;
}