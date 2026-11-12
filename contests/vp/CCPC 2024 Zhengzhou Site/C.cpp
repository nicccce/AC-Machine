#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    auto solve=[&](){
        int a,b,x,y;
        cin>>a>>b>>x>>y;
        if(a==x&&b==y){
            cout<<0<<'\n';
            return;
        }
        int aa=a,bb=b;
        if(aa==0)aa=1;
        if(bb==0)bb=1;
        while(aa%2==0)aa/=2;
        while(bb%2==0)bb/=2;
        if(x%aa!=0||y%bb!=0){
            cout<<-1<<"\n";
            return;
        }
        auto sout=[&](int a0,int b0,int a1,int b1){
            cout<<a0<<" "<<b0<<" "<<a1<<" "<<b1<<"\n";
        };
        auto f=[&](int a,int x,int aa){
            if(x==0){
                return vector<pair<int,int>>{};
            }
            int tmpa=a/aa;
            int tmpx=x/aa;
            while (tmpx%2==0)
            {
                tmpx/=2;
                tmpa/=2;
            }
            int cntn=0;
            int ttmpa=tmpa;
            while (ttmpa%2==0)
            {
                ttmpa/=2;
                cntn++;
            }
            vector<pair<int,int>> ans;
            int now=0;
            for(int i=0;i<cntn;i++){
                if(tmpx&1){
                    ans.push_back({a,now});
                    now=(now+a)/2;
                }else{
                    ans.push_back({0,now});
                    now=now/2;
                }
                tmpx>>=1;
            }
            return ans;
        };
        auto sx=f(a,x,aa),sy=f(b,y,bb);
        if(a==x){
            cout<<sy.size()<<'\n';
            for(int i=0;i<sy.size();i++){
                sout(a,sy[i].first,a,sy[i].second);
            }return;
        }
        if(b==y){
            cout<<sx.size()<<'\n';
            for(int i=0;i<sx.size();i++){
                sout(sx[i].first,b,sx[i].second,b);
            }return;
        }
        reverse(sy.begin(),sy.end());
        while(sx.size()>sy.size()){
            sy.push_back({0,0});
        }
        reverse(sy.begin(),sy.end());
        reverse(sx.begin(),sx.end());
        while(sx.size()<sy.size()){
            sx.push_back({0,0});
        }
        reverse(sx.begin(),sx.end());
        cout<<sx.size()<<'\n';
        for(int i=0;i<sx.size();i++){
            sout(sx[i].first,sy[i].first,sx[i].second,sy[i].second);
        }
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
}