// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int minOperations(vector<string>& logs) {
        int depth = 0;
        for(const string& op : logs) {
            if(op == "../") {
                if(depth > 0) depth--;
            } else if(op != "./") {
                depth++;
            }
        }
        return depth;
    }
};