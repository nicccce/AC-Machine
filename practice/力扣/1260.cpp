// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> result = grid;
        
        for (int _ = 0; _ < k; _++) {
            vector<vector<int>> temp = result;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n - 1; j++) {
                    temp[i][j + 1] = result[i][j];
                }
            }
            
            for (int i = 0; i < m - 1; i++) {
                temp[i + 1][0] = result[i][n - 1];
            }
            
            temp[0][0] = result[m - 1][n - 1];
            result = temp;
        }
        
        return result;
    }
};