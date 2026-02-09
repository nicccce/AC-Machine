#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int cnt = 0;
        int i = 0, j = 1;
        while (cnt < k) {
            bool inArr = false;
            while (i < arr.size() && arr[i] < j) i++;
            if (i < arr.size() && arr[i] == j) inArr = true;
            if (!inArr) cnt++;
            if (cnt == k) return j;
            j++;
        }
        return j;
    }
};