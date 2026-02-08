// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> result = matrix;
        
        for (int j = 0; j < n; j++) {
            int maxVal = -1;
            // Find max value in column j
            for (int i = 0; i < m; i++) {
                maxVal = max(maxVal, matrix[i][j]);
            }
            
            // Replace -1 values in column j with maxVal
            for (int i = 0; i < m; i++) {
                if (matrix[i][j] == -1) {
                    result[i][j] = maxVal;
                }
            }
        }
        
        return result;
    }
};