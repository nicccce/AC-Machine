// https://qoj.ac/contest/2575/problem/14826

#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef complex<double> cd;
const double PI = acos(-1.0);

void iterative_fft(vector<cd> & a, bool invert) {
    int n = a.size();
    int log_n = 0;
    while ((1 << log_n) < n)
        log_n++;
    vector<int> rev(n);
    for (int i = 0; i < n; ++i) {
        rev[i] = 0;
        for (int j = 0; j < log_n; ++j)
            if (i & (1 << j))
                rev[i] |= 1 << (log_n - 1 - j);
    }
 
    for (int i = 0; i < n; ++i)
        if (i < rev[i])
            swap(a[i], a[rev[i]]);
 
    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = w * a[i+j+len/2];
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }
 
    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

vector<int> multiply_polynomials(const vector<int> &a, const vector<int> &b) {
    int n = 1;
    while (n < a.size() + b.size() - 1) n <<= 1;
    
    vector<cd> fa(a.begin(), a.end());
    vector<cd> fb(b.begin(), b.end());
    fa.resize(n);
    fb.resize(n);

    iterative_fft(fa, 0);
    iterative_fft(fb, 0);
    
    for (int i = 0; i < n; i++) {
        fa[i] *= fb[i];
    }
    
    iterative_fft(fa, 1);
    
    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        result[i] = round(fa[i].real());
    }
    

    while (result.size() > 1 && result.back() == 0) 
        result.pop_back();
    
    return result;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    auto solve = [&](){
        int n,ans=0;
        cin>>n;
        string str1,str2,str3;
        cin>>str1>>str2>>str3;
        reverse(str1.begin(),str1.end());
        reverse(str2.begin(),str2.end());
        reverse(str3.begin(),str3.end());
        vector<int> a1(n),a2(n),a3(n),res,pre1(n),pre2(n),pre3(n);
        for(int i=0;i<n;i++)a1[i]=str1[i]-'0',a2[i]=str2[i]-'0',a3[i]=str3[i]-'0';
        pre1[0]=a1[0],pre2[0]=a2[0],pre3[0]=a3[0];
        for(int i=1;i<n;i++)pre1[i]=pre1[i-1]+a1[i],pre2[i]=pre2[i-1]+a2[i],pre3[i]=pre3[i-1]+a3[i];
        res = multiply_polynomials(a1,a2),res.push_back(0),ans+=pre1[n/2]*pre2[n/2]*pre3[n/2];
        for(int i=0;i<n;i++)ans+=-a3[i]*res[n-i];
        for(int i=n/2+1;i<n;i++)ans+=a1[i]*pre2[n-i]*pre3[n-i]+a2[i]*pre1[n-i]*pre3[n-i]+a3[i]*pre2[n-i]*pre1[n-i];
        for(int i=0;i<n;i++)a1[i]=1-a1[i],a2[i]=1-a2[i],a3[i]=1-a3[i];
        pre1[0]=a1[0],pre2[0]=a2[0],pre3[0]=a3[0];
        for(int i=1;i<n;i++)pre1[i]=pre1[i-1]+a1[i],pre2[i]=pre2[i-1]+a2[i],pre3[i]=pre3[i-1]+a3[i];
        res = multiply_polynomials(a1,a2),res.push_back(0),ans+=pre1[n/2]*pre2[n/2]*pre3[n/2];
        for(int i=0;i<n;i++)ans+=-a3[i]*res[n-i];
        for(int i=n/2+1;i<n;i++)ans+=a1[i]*pre2[n-i]*pre3[n-i]+a2[i]*pre1[n-i]*pre3[n-i]+a3[i]*pre2[n-i]*pre1[n-i];
        cout<<ans<<'\n';
    };

    int t;
    for (cin >> t; t--;)
    solve();

    return 0;
}