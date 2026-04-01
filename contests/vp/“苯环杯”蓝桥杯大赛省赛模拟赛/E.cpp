#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    auto solve=[&](){
        int n,k;cin>>n>>k;
        deque<int> q;
        int mx=0;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            q.push_back(x);
            mx=max(mx,x);
        }
        while(k>0&&q.front()!=mx){
            int a=q.front();q.pop_front();
            int b=q.front();q.pop_front();
            if(a>b){
                q.push_front(a);
                q.push_back(b);
            }else{
                q.push_front(b);
                q.push_back(a);
            }
            k--;
        }
        if(k>0){
            int rem=k%(n-1);
            int top=q.front();q.pop_front();
            while(rem--){
                int x=q.front();q.pop_front();
                q.push_back(x);
            }
            q.push_front(top);
        }
        for(int i=0;i<n;i++)cout<<q[i]<<(i==n-1?"":" ");
        cout<<"\n";
    };
    int t;cin>>t;
    while(t--)solve();
    return 0;
}