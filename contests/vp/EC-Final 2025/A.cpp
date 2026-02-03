#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef __int128 i128;
struct Pt{
    i128 x,y;
};
Pt sub(Pt a,Pt b){return{a.x-b.x,a.y-b.y};}
i128 cross(Pt a,Pt b){return a.x*b.y-a.y*b.x;}
i128 dot(Pt a,Pt b){return a.x*b.x+a.y*b.y;}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto solve=[&](){
        int xa,ya,xb,yb,xc,yc;
        cin>>xa>>ya>>xb>>yb>>xc>>yc;
        int xd1,xd2,yd1,yd2;char s;
        cin>>xd1>>s>>xd2>>yd1>>s>>yd2;
        Pt A0={xa,ya},B0={xb,yb},C0={xc,yc};
        Pt AB0=sub(B0,A0),AC0=sub(C0,A0),BC0=sub(C0,B0);
        i128 L=(i128)xd2*yd2;
        Pt As={(i128)xa*L,(i128)ya*L},Bs={(i128)xb*L,(i128)yb*L},Cs={(i128)xc*L,(i128)yc*L};
        Pt Ds={(i128)xd1*yd2,(i128)yd1*xd2};
        Pt ABs=sub(Bs,As),ACs=sub(Cs,As),BCs=sub(Cs,Bs),ADs=sub(Ds,As);
        i128 hc=cross(ABs,ACs),hd=cross(ABs,ADs);
        if(hd==0||hd==hc){cout<<"Yes\n";return;}
        bool in_strip=(hc>0&&hd>0&&hd<=hc)||(hc<0&&hd<0&&hd>=hc);
        if(!in_strip){cout<<"No\n";return;}
        auto check=[&](Pt start_s,Pt dir_0,Pt base_0,Pt target_s)->bool{
            i128 num=cross(sub(target_s,start_s),dir_0);
            i128 den=cross(base_0,dir_0);
            if(den==0)return false;
            i128 modulus=den*L;
            return num%modulus==0;
        };
        if(check(As,AC0,AB0,Ds)||check(Bs,BC0,AB0,Ds)){cout<<"Yes\n";return;}
        if(dot(AB0,AC0)==0){
            i128 val=cross(sub(Ds,As),AC0);
            i128 limit=cross(sub(Bs,As),AC0);
            bool strictly_inside=false;
            if(limit>0)strictly_inside=(val>0&&val<limit);
            else if(limit<0)strictly_inside=(val<0&&val>limit);
            if(!strictly_inside){
                i128 da=dot(AC0,AC0),db=dot(BC0,AC0);
                Pt dir0;
                dir0.x=2*db*AC0.x-da*BC0.x;
                dir0.y=2*db*AC0.y-da*BC0.y;
                if(check(Cs,dir0,AB0,Ds)){cout<<"Yes\n";return;}
            }
        }
        if(dot(AB0,BC0)==0){
            i128 val=cross(sub(Ds,Bs),BC0);
            i128 limit=cross(sub(As,Bs),BC0);
            bool strictly_inside=false;
            if(limit>0)strictly_inside=(val>0&&val<limit);
            else if(limit<0)strictly_inside=(val<0&&val>limit);
            if(!strictly_inside){
                i128 db=dot(BC0,BC0),da=dot(AC0,BC0);
                Pt dir0;
                dir0.x=2*da*BC0.x-db*AC0.x;
                dir0.y=2*da*BC0.y-db*AC0.y;
                if(check(Cs,dir0,AB0,Ds)){cout<<"Yes\n";return;}
            }
        }
        cout<<"No\n";
    };
    int t;
    if(cin>>t)while(t--)solve();
    return 0;
}