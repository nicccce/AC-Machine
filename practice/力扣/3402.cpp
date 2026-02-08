// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int total_ops = 0;
        
        for (int j = 0; j < m; j++) {  // 遏列
            for (int i = 1; i < n; i++) {  // 从第二行开始
                if (grid[i][j] <= grid[i-1][j]) {
                    int needed = grid[i-1][j] + 1;
                    total_ops += needed - grid[i][j];
                    grid[i][j] = needed;
                }
            }
        }
        
        return total_ops;
    }
};