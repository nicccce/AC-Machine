#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define int long long
char w[100005];
void solve(){
    int ans=0,flag=0,l=0;
    char ch;
    while((ch=getchar())!=EOF){
        if(ch!=' '&&ch!='\n'&&ch!='\r'){
            if(ch>='A'&&ch<='Z')ch^=' ';
            w[l++]=ch;
        }else{
            if(l>0){
                w[l]='\0';
                if(!flag)
                    flag=(strncmp(w,"cac",3)==0
                    ||(l>=3&&strcmp(w+l-3,"tus")==0)
                    ||strstr(w,"cactus"));
                l=0;
            }
            if(ch=='\n')
                ans+=flag,flag=0;
        }
    }
    if(l>0){
        w[l]='\0';
        if(!flag)
            flag=(strncmp(w,"cac",3)==0
            ||(l>=3&&strcmp(w+l-3,"tus")==0)
            ||strstr(w,"cactus"));
        
    }
    ans+=flag,flag=0;
    printf("%d\n",ans);
}
signed main() {
    int t=1;
    // scanf("%d",&t);
    for(;t;t--)solve();
    return 0;
}