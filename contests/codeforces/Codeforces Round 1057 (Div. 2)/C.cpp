#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        set<int> st;
        int n;
        cin>>n;
        int summ=0,scnt=0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(st.count(x)){
                summ+=x;
                scnt++;
                st.erase(x);
            }else{
                st.insert(x);
            }
        }if(scnt==0){
            cout<<0<<'\n';
            return;
        }
        if(st.size()==0){
        p1:
           if(scnt==1){
            cout<<0<<'\n';
            return;
           }
           cout<<summ*2<<'\n';
           return;
        }
        if(st.size()==1){
        p2:
            int x=*st.begin();
            if(x>=summ*2){
                goto p1;
            }
            cout<<summ*2+x<<'\n';
            return;
        }else{
            for(auto i=(--st.end());i!=st.begin();){
                int a=*i;
                i--;
                int b=*i;
                if(a-b<summ*2){
                    cout<<summ*2+a+b<<'\n';
                    return;
                }
            }
            goto p2;
        }
        
    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}