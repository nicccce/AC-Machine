#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define int long long
void solve(){
    int n,a=0,x,y,X,Y,fx,fy;
    scanf("%lld%lld%lld",&n,&fx,&fy);
    x=fx;y=fy;
    while(--n){
        scanf("%lld%lld",&X,&Y);
        a+=x*Y-X*y;
        x=X;y=Y;
    }
    a+=x*fy-fx*y;
    printf("%lld\n",a<0?-a/2:a/2);
}
signed main(){
    int t;
    scanf("%lld",&t);
    while(t--)solve();
    return 0;
}