// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> mp;
        
        for (auto& item : items1) {
            mp[item[0]] += item[1];
        }
        
        for (auto& item : items2) {
            mp[item[0]] += item[1];
        }
        
        vector<vector<int>> result;
        for (auto& p : mp) {
            result.push_back({p.first, p.second});
        }
        
        return result;
    }
};