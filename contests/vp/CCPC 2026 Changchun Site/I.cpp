#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;

signed main(){
    int r;
    auto solve=[&](){
        if(r==1){
            int n;cin>>n;
            string s;cin>>s;
            int cnt0=0,lp0,lp1;
            for(int i=0;i<n;i++)cnt0+=(s[i]=='0');
            int fst=s[0]-'0';
            if(cnt0<n-cnt0)lp0=2,lp1=1;
            else lp0=1,lp1=2;
            string ans;
            for(int i=0;i<n;i++){
                if(s[i]=='0'){
                    for(int i=0;i<lp0;i++)ans.push_back('0'+fst);
                    fst=(fst^1);
                }else{
                    for(int i=0;i<lp1;i++)ans.push_back('0'+fst);
                    fst=(fst^1);
                }
            }
            cout<<ans.length()<<'\n'<<ans;
            cout<<endl;
        }else{
            int n;cin>>n;
            string s;cin>>s;
            int lp1,lp2;
            string ans;
            if(s[0]==s[1]){
                lp2=s[0]-'0';
                lp1=(lp2^1);
            }else{
                lp1=s[0]-'0';
                lp2=(lp1^1);
            }
            for(int i=0;i<n;i++){
                if(s[i]==s[i+1]){
                    ans.push_back('0'+lp2);
                    i++;
                }else{
                    ans.push_back('0'+lp1);
                }
            }
            cout<<ans.length()<<'\n'<<ans;
            cout<<endl;
        }
    };
    int t;
    for(cin>>t,cin>>r;t;t--)
    solve();
}