// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int min_time = INT_MAX;
        
        // 陆地游乐设施 -> 水上游乐设施
        for (int i = 0; i < landStartTime.size(); i++) {
            int land_end = landStartTime[i] + landDuration[i];
            for (int j = 0; j < waterStartTime.size(); j++) {
                int water_start = max(land_end, waterStartTime[j]);
                int water_end = water_start + waterDuration[j];
                min_time = min(min_time, water_end);
            }
        }
        
        // 水上游乐设施 -> 陆地游乐设施
        for (int i = 0; i < waterStartTime.size(); i++) {
            int water_end = waterStartTime[i] + waterDuration[i];
            for (int j = 0; j < landStartTime.size(); j++) {
                int land_start = max(water_end, landStartTime[j]);
                int land_end = land_start + landDuration[j];
                min_time = min(min_time, land_end);
            }
        }
        
        return min_time;
    }
};