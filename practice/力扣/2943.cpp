// https://leetcode.cn/problems/maximize-area-of-square-hole-in-grid/description/?envType=daily-question&envId=2026-01-20
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int hmax=1,vmax=1,hcur=1,vcur=1;
        for (int i = 1; i < hBars.size(); i++) {
            if (hBars[i] == hBars[i - 1] + 1) {
                hcur++;
            } else {
                hcur = 1;
            }
            hmax = max(hmax, hcur);
        }
        for (int i = 1; i < vBars.size(); i++) {
            if (vBars[i] == vBars[i - 1] + 1) {
                vcur++;
            } else {
                vcur = 1;
            }
            vmax = max(vmax, vcur);
        }
        int ans = min(hmax, vmax) + 1;
        return ans * ans;
    }
};