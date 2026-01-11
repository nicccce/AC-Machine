#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n;
        cin >> n;
        vector<string> grid(n);
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }

        // 找到所有'#'的位置
        vector<pair<int, int>> hashes;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '#') {
                    hashes.push_back({i, j});
                }
            }
        }

        int max_area = -1;
        vector<int> best_square(4); // 存储四个顶点的索引

        // 遍历所有可能的点对
        for (int i = 0; i < hashes.size(); i++) {
            for (int j = 0; j < hashes.size(); j++) {
                if (i == j) continue;
                
                int x1 = hashes[i].first, y1 = hashes[i].second;
                int x2 = hashes[j].first, y2 = hashes[j].second;
                
                // 计算向量 (x2-x1, y2-y1)
                int dx = x2 - x1;
                int dy = y2 - y1;
                
                // 通过旋转90度得到另外两个点
                // 如果(x1,y1)和(x2,y2)是相邻顶点，则另外两个顶点是:
                // (x1-dy, y1+dx) 和 (x2-dy, y2+dx) 或 (x1+dy, y1-dx) 和 (x2+dy, y2-dx)
                
                // 情况1: 另外两个点是 (x1-dy, y1+dx) 和 (x2-dy, y2+dx)
                int x3 = x1 - dy, y3 = y1 + dx;
                int x4 = x2 - dy, y4 = y2 + dx;
                
                if (x3 >= 0 && x3 < n && y3 >= 0 && y3 < n &&
                    x4 >= 0 && x4 < n && y4 >= 0 && y4 < n &&
                    grid[x3][y3] == '#' && grid[x4][y4] == '#') {
                    
                    int area = dx * dx + dy * dy; // 正方形面积
                    if (area > max_area) {
                        max_area = area;
                        // 找到x3和x4在hashes中的索引
                        int idx3 = -1, idx4 = -1;
                        for (int k = 0; k < hashes.size(); k++) {
                            if (hashes[k].first == x3 && hashes[k].second == y3) {
                                idx3 = k;
                            }
                            if (hashes[k].first == x4 && hashes[k].second == y4) {
                                idx4 = k;
                            }
                        }
                        best_square[0] = i;
                        best_square[1] = j;
                        best_square[2] = idx3;
                        best_square[3] = idx4;
                    }
                }
                
                // 情况2: 另外两个点是 (x1+dy, y1-dx) 和 (x2+dy, y2-dx)
                x3 = x1 + dy, y3 = y1 - dx;
                x4 = x2 + dy, y4 = y2 - dx;
                
                if (x3 >= 0 && x3 < n && y3 >= 0 && y3 < n &&
                    x4 >= 0 && x4 < n && y4 >= 0 && y4 < n &&
                    grid[x3][y3] == '#' && grid[x4][y4] == '#') {
                    
                    int area = dx * dx + dy * dy; // 正方形面积
                    if (area > max_area) {
                        max_area = area;
                        // 找到x3和x4在hashes中的索引
                        int idx3 = -1, idx4 = -1;
                        for (int k = 0; k < hashes.size(); k++) {
                            if (hashes[k].first == x3 && hashes[k].second == y3) {
                                idx3 = k;
                            }
                            if (hashes[k].first == x4 && hashes[k].second == y4) {
                                idx4 = k;
                            }
                        }
                        best_square[0] = i;
                        best_square[1] = j;
                        best_square[2] = idx3;
                        best_square[3] = idx4;
                    }
                }
            }
        }

        // 输出四个顶点的坐标（从1开始编号）
        cout << hashes[best_square[0]].first + 1 << " " << hashes[best_square[0]].second + 1 << "\n";
        cout << hashes[best_square[1]].first + 1 << " " << hashes[best_square[1]].second + 1 << "\n";
        cout << hashes[best_square[2]].first + 1 << " " << hashes[best_square[2]].second + 1 << "\n";
        cout << hashes[best_square[3]].first + 1 << " " << hashes[best_square[3]].second + 1 << "\n";
    };
    // int t;
    // for(cin>>t;t;t--)
    solve();
    return 0;
}