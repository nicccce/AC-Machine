#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n,m,k;
        cin>>n>>m>>k;
        vector<pair<int,int>> a(n),b(m);
        for(int i=0;i<n;i++){cin>>a[i].first;a[i].second=i;}
        for(int i=0;i<m;i++){cin>>b[i].first;b[i].second=i;}
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int t1=a[n-1].first+k,t2,nt=a[n-1].first+k,pa=n-1,pb=m-1;
        while (pa>=0||pb>=0)
        {
            nt-=k;
            if(pa>=0){
                if(a[pa].first>nt)t1+=a[pa].first-nt,nt=a[pa].first;
                pa--;
            }
            nt-=k;
            if(pb>=0){
                if(b[pb].first>nt)t1+=b[pb].first-nt,nt=b[pb].first;
                pb--;
            }
        }
        t2=b[m-1].first+k,nt=b[m-1].first+k,pa=n-1,pb=m-1;
        while (pa>=0||pb>=0)
        {
            nt-=k;
            if(pb>=0){
                if(b[pb].first>nt)t2+=b[pb].first-nt,nt=b[pb].first;
                pb--;
            }
            nt-=k;
            if(pa>=0){
                if(a[pa].first>nt)t2+=a[pa].first-nt,nt=a[pa].first;
                pa--;
            }
        }
        vector<pair<int,pair<int,int>>> ans;
        if(t1<t2){
            cout<<t1<<'\n';
            nt=t1,pa=n-1,pb=m-1;
            while (pa>=0||pb>=0)
            {
                nt-=k;
                if(pa>=0){
                    ans.push_back({nt,{0,a[pa].second+1}});
                    pa--;
                }
                nt-=k;
                if(pb>=0){
                    ans.push_back({nt,{1,b[pb].second+1}});
                    pb--;
                }
            }
        }else{
            cout<<t2<<'\n';
            nt=t2,pa=n-1,pb=m-1;
            while (pa>=0||pb>=0)
            {
                nt-=k;
                if(pb>=0){
                    ans.push_back({nt,{1,b[pb].second+1}});
                    pb--;
                }
                nt-=k;
                if(pa>=0){
                    ans.push_back({nt,{0,a[pa].second+1}});
                    pa--;
                }
            }
        }
        sort(ans.begin(),ans.end());
        for(auto i:ans){
            cout<<i.first<<' '<<i.second.first<<' '<<i.second.second<<'\n';
        }
    };

    solve();
    return 0;
}