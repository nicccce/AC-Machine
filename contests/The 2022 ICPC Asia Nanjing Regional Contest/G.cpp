// https://codeforces.com/gym/104128/problem/G
#include <bits/stdc++.h>
using namespace std;
int main(){
    int t,n,s,c,a,cnt,f;
    auto solve = [&](){
        for(cin>>n,c=s=1,cnt=f=0;n;n--){
            cin>>a;if(f)continue;
            if(a==1)c++,s++;
            if(a==-1){
                if(c==1){
                    f=(cnt==0);
                    if(cnt>0)c++,s++,cnt--;
                }else c--;
            }
            if(a==0){
                if(c==1)c++,s++;
                else c--,cnt++;
            }
        }
        if(f==1)cout<<"-1\n";
        else cout<<s/__gcd(s,c)<<' '<<c/__gcd(s,c)<<'\n';
    };
    for(cin>>t;t;t--)solve();
}