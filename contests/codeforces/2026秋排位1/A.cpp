// https://codeforces.com/contest/1216/problem/C
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
struct point{
    int x,y;
    int size(){
        return x*y;
    }
};
// int cnt(point al,point ar,point bl,point br){
//     if(bl.x>al.x){
//         swap(al,bl);swap(ar,br);
//     }
//     if(bl.y<al.y){
//         if(br.x<ar.x&&br.y<ar.y){
//             return max(0,br.x-al.x)*max(0,br.y-al.y);
//         }
//         if(br.x<ar.x&&br.y>ar.y){
//             return max(0,br.x-al.x)*(ar.y-al.y);
//         }
//         if(br.x>ar.x&&br.y>ar.y){
//             return (ar.x-al.x)*(ar.y-al.y);
//         }
//         return (ar.x-al.x)*max(0,br.y-al.y);
//     }else{
//         if(br.x<ar.x&&br.y<ar.y){
//             return max(0,br.x-al.x)*(br.y-bl.y);
//         }
//         if(br.x<ar.x&&br.y>ar.y){
//             return max(0,br.x-al.x)*max(0,ar.y-bl.y);
//         }
//         if(br.x>ar.x&&br.y>ar.y){
//             return (ar.x-al.x)*max(0,ar.y-bl.y);
//         }
//         return (ar.x-al.x)*(br.y-bl.y);
//     }
// }
pair<point,point> cnt(point al,point ar,point bl,point br){
    if(bl.x>al.x){
        swap(al,bl);swap(ar,br);
    }
    if(bl.y<al.y){
        if(br.x<ar.x&&br.y<ar.y){
            return {{al.x,al.y},{max(al.x,br.x),max(al.y,br.y)}};
            // max(0,br.x-al.x)*max(0,br.y-al.y);
        }
        if(br.x<ar.x&&br.y>=ar.y){
            return {{al.x,al.y},{max(al.x,br.x),max(al.y,ar.y)}};
            // return max(0,br.x-al.x)*(ar.y-al.y);
        }
        if(br.x>=ar.x&&br.y>=ar.y){
            return {{al.x,al.y},{max(al.x,ar.x),max(al.y,ar.y)}};
            // return (ar.x-al.x)*(ar.y-al.y);
        }
            return {{al.x,al.y},{max(al.x,ar.x),max(al.y,br.y)}};
        // return (ar.x-al.x)*max(0,br.y-al.y);
    }else{
        if(br.x<ar.x&&br.y<ar.y){
            return {{al.x,bl.y},{max(al.x,br.x),max(bl.y,br.y)}};
            // return max(0,br.x-al.x)*(br.y-bl.y);
        }
        if(br.x<ar.x&&br.y>=ar.y){
            return {{al.x,bl.y},{max(al.x,br.x),max(bl.y,ar.y)}};
            // return max(0,br.x-al.x)*max(0,ar.y-bl.y);
        }
        if(br.x>=ar.x&&br.y>=ar.y){
            return {{al.x,bl.y},{max(al.x,ar.x),max(bl.y,ar.y)}};
            // return (ar.x-al.x)*max(0,ar.y-bl.y);
        }
        return {{al.x,bl.y},{max(al.x,ar.x),max(bl.y,br.y)}};
        // return (ar.x-al.x)*(br.y-bl.y);
    }
}
int cs(pair<point,point> a){
    return (a.second.x-a.first.x)*(a.second.y-a.first.y);
}
signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        point wl,wr,b1l,b1r,b2l,b2r;
        cin>>wl.x>>wl.y>>wr.x>>wr.y;
        cin>>b1l.x>>b1l.y>>b1r.x>>b1r.y;
        cin>>b2l.x>>b2l.y>>b2r.x>>b2r.y;
        // cout<<cs(cnt(wl,wr,b1l,b1r))-cs(cnt(cnt(b2l,b2r,b1l,b1r).first,cnt(b2l,b2r,b1l,b1r).second,wl,wr))+cs(cnt(wl,wr,b2l,b2r))<<'\n';
        // cout<<cs(pair<point,point>{wl,wr})<<'\n';
        if(cs(cnt(wl,wr,b1l,b1r))+cs(cnt(wl,wr,b2l,b2r))-cs(cnt(cnt(b2l,b2r,b1l,b1r).first,cnt(b2l,b2r,b1l,b1r).second,wl,wr))<cs(pair<point,point>{wl,wr})){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}