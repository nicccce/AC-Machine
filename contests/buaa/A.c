#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define int long long
void solve(){
    int n,x,m1=0,m2=0;
    scanf("%lld",&n);
    while(n--){
        scanf("%lld",&x);
        if(x>m1){m2=m1;m1=x;}
        else if(x>m2)m2=x;
    }
    printf("%lld\n",m1+m2);
}
signed main() {
    int t=1;
    scanf("%d",&t);
    for(;t;t--)solve();
    return 0;
}