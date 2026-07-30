#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define int long long
#define inf 0x3f3f3f3f
void solve(){
    char s[105];
    int n,i,j,d,l,nj,nd,df,ans=0;
    scanf("%s%lld",s,&n);
    l=strlen(s);
    int mx[105][55][2],mn[105][55][2];
    for(i=0;i<=l;i++)for(j=0;j<=n;j++)for(d=0;d<2;d++){
        mx[i][j][d]=-inf;
        mn[i][j][d]=inf;
    }
    mx[0][0][0]=0;
    mn[0][0][0]=0;
    for(i=0;i<l;i++){
        for(j=0;j<=n;j++){
            for(d=0;d<2;d++){
                if(mx[i][j][d]==-inf)continue;
                nj=j+(s[i]!='F');
                if(nj<=n){
                    df=d?-1:1;
                    mx[i+1][nj][d]=max(mx[i+1][nj][d],mx[i][j][d]+df);
                    mn[i+1][nj][d]=min(mn[i+1][nj][d],mn[i][j][d]+df);
                }
                nj=j+(s[i]!='T');
                if(nj<=n){
                    nd=1-d;
                    mx[i+1][nj][nd]=max(mx[i+1][nj][nd],mx[i][j][d]);
                    mn[i+1][nj][nd]=min(mn[i+1][nj][nd],mn[i][j][d]);
                }
            }
        }
    }
    for(j=n%2;j<=n;j+=2)
        for(d=0;d<2;d++)
            ans=max(max(ans,mx[l][j][d]),-mn[l][j][d]);
    printf("%lld\n",ans);
}

signed main(){
    int t=1;
    //scanf("%lld",&t);
    for(;t;t--)
        solve();
    return 0;
}