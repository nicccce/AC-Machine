#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define int long long
char c[603][603];
int w[7]={3,6,16,32,84,168,440};
void f(int n,int x,int y){
    if(!n){
        c[x][y+1]=c[x+1][y]=c[x+1][y+2]=c[x+2][y+1]='o';
        return;
    }
    int k;
    if(n&1){
        k=w[n-1];
        f(n-1,x,y);
        f(n-1,x+k,y);
        f(n-1,x,y+k);
        f(n-1,x+k,y+k);
    }else{
        if(n==2)k=w[n-1]-1;
        else k=w[n-1]-w[n-3];
        f(n-1,x,y+k);
        f(n-1,x+k,y);
        f(n-1,x+k,y+2*k);
        f(n-1,x+2*k,y+k);
    }
}
void solve(){
    int n,i,j,last;
    scanf("%lld",&n);
    for(i=0;i<w[n];i++)for(j=0;j<w[n];j++)c[i][j]=' ';
    f(n,0,0);
    for(i=0;i<w[n];i++){
        last=w[n]-1;
        while(last>=0&&c[i][last]==' ')last--;
        for(j=0;j<=last;j++)putchar(c[i][j]);
        if(i!=w[n]-1)putchar('\n');
    }
}
signed main(){
    int t;
    // scanf("%lld",&t);
    // for(;t;t--)
    solve();
    return 0;
}
