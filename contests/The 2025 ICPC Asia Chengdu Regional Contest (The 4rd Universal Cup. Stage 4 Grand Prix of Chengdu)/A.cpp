#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        int summ=0,cnt0=0;
        for(int i=0;i<n;i++){
            summ+=a[i];
            cnt0+=(a[i]==0);
        }

        summ-=100;
        if(summ==0){
            cout<<"YES\n";
            for(int i=0;i<n;i++){
                cout<<a[i]<<' ';
            }cout<<'\n';
            return;
        }else{
            for(int i=0;i<n;i++){
                a[i]*=1000000;
            }
            if(summ>0){
                if((n-cnt0)<summ*2){
                    cout<<"NO\n";
                    return;
                }
                cout<<"YES\n";
                int z = summ*1000000/(n-cnt0);
                for(int i=0;i<n;i++){
                    if(a[i]==0)cout<<a[i]<<' ';
                    else cout<<a[i]-z<<' ';
                }cout<<'\n';
                return;
            }
            if(summ<0){
                summ=-summ;
                if(n<=summ*2){
                    cout<<"NO\n";
                    return;
                }
                cout<<"YES\n";
                int z = summ*1000000/n;
                for(int i=0;i<n;i++){
                    cout<<a[i]+z<<' ';
                }cout<<'\n';
                return;
            }
            
        }

    };
    int t;
    for(cin>>t;t;t--)
    solve();
    return 0;
}