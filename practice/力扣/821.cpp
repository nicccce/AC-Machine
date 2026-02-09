#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.length();
        vector<int> result(n);
        
        // 找到所有字符c的位置
        vector<int> positions;
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                positions.push_back(i);
            }
        }
        
        // 对每个位置计算到最近的c的距离
        for (int i = 0; i < n; i++) {
            int minDist = INT_MAX;
            for (int pos : positions) {
                minDist = min(minDist, abs(i - pos));
            }
            result[i] = minDist;
        }
        
        return result;
    }
};