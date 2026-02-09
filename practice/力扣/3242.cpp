#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class NeighborSum {
private:
    vector<vector<int>> g;
    int n;
    unordered_map<int, pair<int, int>> pos;
    
public:
    NeighborSum(vector<vector<int>>& grid) {
        g = grid;
        n = grid.size();
        
        // 记录每个值的位置
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pos[g[i][j]] = {i, j};
            }
        }
    }
    
    int adjacentSum(int value) {
        auto [x, y] = pos[value];
        int sum = 0;
        
        // 上
        if (x > 0) sum += g[x-1][y];
        // 下
        if (x < n-1) sum += g[x+1][y];
        // 左
        if (y > 0) sum += g[x][y-1];
        // 右
        if (y < n-1) sum += g[x][y+1];
        
        return sum;
    }
    
    int diagonalSum(int value) {
        auto [x, y] = pos[value];
        int sum = 0;
        
        // 左上
        if (x > 0 && y > 0) sum += g[x-1][y-1];
        // 右上
        if (x > 0 && y < n-1) sum += g[x-1][y+1];
        // 左下
        if (x < n-1 && y > 0) sum += g[x+1][y-1];
        // 右下
        if (x < n-1 && y < n-1) sum += g[x+1][y+1];
        
        return sum;
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */