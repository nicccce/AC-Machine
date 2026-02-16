// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        auto canBuild = [](int color1, int color2) -> int {
            int height = 0;
            int row = 1;
            
            while (true) {
                if (row % 2 == 1) { // odd rows use color1
                    if (color1 >= row) {
                        color1 -= row;
                        height++;
                    } else {
                        break;
                    }
                } else { // even rows use color2
                    if (color2 >= row) {
                        color2 -= row;
                        height++;
                    } else {
                        break;
                    }
                }
                row++;
            }
            
            return height;
        };
        
        // Try starting with red, then try starting with blue
        int height1 = canBuild(red, blue);
        int height2 = canBuild(blue, red);
        
        return max(height1, height2);
    }
};