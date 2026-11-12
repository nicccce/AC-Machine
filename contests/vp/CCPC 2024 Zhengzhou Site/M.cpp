#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
signed main(){
    auto solve=[&](){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        int amin=LONG_LONG_MAX,amax=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            amin = min(amin, a[i]);
            amax = max(amax, a[i]);
        }
        vector<int> b(a);
        sort(b.begin(),b.end());
        auto check=[&](double x){
            double cnt=0;
            for(int i=n-1;i>=0;i--){
                cnt+=b[i]/(x+b[i]);
            }
            return cnt>k;
        };
        double l = (double)amin * (n - k) / k;
        double r = (double)amax * (n - k) / k;
        const double eps = 1e-8;
        for(int i=0;i<100;i++){
            double mid = (l + r) / 2;
            if (check(mid))
                l = mid;
            else
                r = mid;
        }
        #undef double
        for(int i=0;i<n;i++){
            printf("%.12lf\n",a[i]/((double)l+a[i]));
        }
    };
    int t;
    // for(cin>>t;t;t--)
    solve();
}