#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define int long long
int f[95];
int p(int x){
    int i=1;
    while(f[i]<x){
        i++;
    }
    return f[i]-x+1;
}
void solve(){
    int a,b;
    scanf("%lld%lld",&a,&b);
    while(a!=b){
        if(a>b){
            a=p(a);
        }else{
            b=p(b);
        }
    }
    printf("%lld\n",a);
}
signed main(){
    f[1]=1;
    for(int i=2;i<95;i++){
        f[i]=f[i-1]+f[i-2];
    }
    int t;
    scanf("%lld",&t);
    for(;t;t--){
        solve();
    }
    return 0;
}