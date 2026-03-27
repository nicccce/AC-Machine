#include <bits/stdc++.h>
using namespace std;
#define int long long

const int dim=102;
const int mod=1e9+7;
struct matrix{
    int m[dim][dim];
};

matrix operator * (const matrix& a, const matrix& b){
    matrix c;
    memset(c.m, 0, sizeof(c.m));

    for(int i=0; i<dim; i++)
        for(int j=0; j<dim; j++)
            for(int k=0; k<dim; k++)
                c.m[i][j] = (c.m[i][j] + a.m[i][k]*b.m[k][j]) % mod;
    return c;
}

matrix qpow_matrix(matrix a, int n){
    matrix ans;
    memset(ans.m, 0, sizeof(ans.m));
    for(int i=0; i<dim; i++) ans.m[i][i] = 1;
    while(n){
        if(n & 1)
            ans = ans * a;
        a = a * a;
        n >>= 1;
    }
    return ans;
}
signed main(){

    auto solve=[&](){
        int n,k;
        vector<int> t(101);
        int x;
        cin>>n>>k;
        for(int i=1;i<k;i++){
            cin>>x;
            t[x]++;
        }
        matrix base;
        for(int i=0;i<101;i++){
            for(int j=0;j<100;j++){
                base.m[i][j]=t[j+1];
            }
            base.m[i][101]=k;
        }
        for(int i=1;i<100;i++){
            base.m[i][i-1]++;
        }
        base.m[100][100]+=1;
        base.m[101][101]=1;
        vector<int> ini(102);
        ini[101]=1;
        ini[99]=t[0]+1;
        ini[100]=ini[99];
        // cout<<t[0]+1<<'\n';
        for(int i=1;i<100;i++){
            if(i==n){
                cout<<ini[100]<<'\n';
                return;
            }
            int dif=t[0]+1;
            for(int j=0;j<i;j++){
                dif+=t[i-j]*(ini[99-j]+1)%mod;
            }
            ini[100]+=dif;
            ini[100]%=mod;
            for(int j=99;j>=99-i;j--){
                ini[j]+=dif;
                ini[j]%=mod;
            }
        }
        auto mul = qpow_matrix(base,n-100);
        vector<int> ansvec(102);
        for(int i=0; i<dim; i++)
            for(int j=0; j<dim; j++)
                ansvec[i] = (ini[j]*mul.m[i][j]%mod + ansvec[i]) % mod;
        cout<<ansvec[100]<<'\n';
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();

}