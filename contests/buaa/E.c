#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define int long long
int h[2][200005],s[2];
void push(int id,int v){
    int i=++s[id];
    while(i>1&&h[id][i/2]<v){
        h[id][i]=h[id][i/2];i/=2;
    }
    h[id][i]=v;
}
int pop(int id){
    int r=h[id][1],v=h[id][s[id]--],i=1,c;
    while((c=i*2)<=s[id]){
        if(c<s[id]&&h[id][c]<h[id][c+1])c++;
        if(v>=h[id][c])break;
        h[id][i]=h[id][c];i=c;
    }
    h[id][i]=v;return r;
}
void solve(){
    int q,op,a,b,sb=0,sl=0,sr=0,k=0,v;
    if(scanf("%lld",&q)!=1)return;
    while(q--){
        scanf("%lld",&op);
        if(op==1){
            scanf("%lld%lld",&a,&b);
            sb+=b;k++;
            if(!s[0]||a<=h[0][1]){
                push(0,a);
                sl+=a;
            }else{
                push(1,-a);
                sr+=a;
            }
            if(s[0]>s[1]+1){
                v=pop(0);
                sl-=v;
                push(1,-v);
                sr+=v;
            }
            if(s[0]<s[1]){
                v=-pop(1);
                sr-=v;
                push(0,v);
                sl+=v;}
        }else{
            v=h[0][1];
            printf("%lld %lld\n",v,sr-sl+sb+(k%2?v:0));
        }
    }
}
signed main() {
    int t=1;
    // scanf("%d",&t);
    // for(;t;t--)
    solve();
    return 0;
}