// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        });
        
        int totalUnits = 0;
        int boxesLoaded = 0;
        
        for (auto& boxType : boxTypes) {
            int boxes = boxType[0];
            int unitsPerBox = boxType[1];
            
            if (boxesLoaded + boxes <= truckSize) {
                totalUnits += boxes * unitsPerBox;
                boxesLoaded += boxes;
            } else {
                int remainingSpace = truckSize - boxesLoaded;
                totalUnits += remainingSpace * unitsPerBox;
                break;
            }
        }
        
        return totalUnits;
    }
};