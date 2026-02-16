#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int ans=target[0],n=target.size();
        for(int i=1;i<n;i++)ans+=max(0,target[i]-target[i-1]);
        return ans;
    }
};