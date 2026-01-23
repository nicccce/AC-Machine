// https://leetcode.cn/problems/max-points-on-a-line/description/?envType=problem-list-v2&envId=math
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        map<array<int, 3>, int> cnt;
        int mx = 0;
        for (int i = 0; i < n; ++i) 
            for(int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0], dy = points[j][1] - points[i][1];
                if(dx==0){
                    cnt[{1,0,points[i][0]}]++;
                    mx=max(mx,cnt[{1,0,points[i][0]}]);
                }else if(dy==0){
                    cnt[{0,1,points[i][1]}]++;
                    mx=max(mx,cnt[{0,1,points[i][1]}]);
                }else{
                    int g = __gcd(abs(dx), abs(dy));
                    dx /= g; dy /= g;
                    if(dx<0) dx=-dx,dy=-dy;
                    int c = points[i][1]*dx - points[i][0]*dy;
                    cnt[{dx,dy,c}]++;
                    mx=max(mx,cnt[{dx,dy,c}]);
                }
            }
        int ans=1;
        return round((1+sqrt(8*mx+1))/2);
        
    }
};