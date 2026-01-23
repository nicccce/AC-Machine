// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int> cnt0,cnt1,cnt2,cnt3,cnt;
        for(auto &rec:rectangles){
            int x1=rec[0],y1=rec[1],x2=rec[2],y2=rec[3];
            cnt[{x1,y1}]++;
            cnt[{x1,y2}]++;
            cnt[{x2,y1}]++;
            cnt[{x2,y2}]++;
            cnt0[{x1,y1}]++;
            cnt1[{x1,y2}]++;
            cnt2[{x2,y2}]++;
            cnt3[{x2,y1}]++;
        }
        int cnt11=0;
        set<int> cntx,cnty;

        for(auto [k,v]:cnt){
            if(v==1){
                cnt11++;
                cntx.insert(k.first);
                cnty.insert(k.second);
            }else if(v==2){
                if((cnt0[k]!=1||cnt1[k]!=1)&&(cnt1[k]!=1||cnt2[k]!=1)&&(cnt2[k]!=1||cnt3[k]!=1)&&(cnt0[k]!=1||cnt3[k]!=1))
                return false;
            }else if(v==4){
                if(cnt0[k]!=1||cnt3[k]!=1||cnt1[k]!=1||cnt2[k]!=1)
                return false;
            }else{
                return false;
            }
        }
        if(cnt11!=4||cntx.size()!=2||cnty.size()!=2) return false;
        return true;
    }
};