// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    string oddString(vector<string>& words) {
        int n = words[0].size();
        
        auto getDiffArray = [&](const string& s) -> vector<int> {
            vector<int> diff(n - 1);
            for (int i = 0; i < n - 1; i++) {
                diff[i] = s[i + 1] - s[i];
            }
            return diff;
        };
        
        vector<int> diff0 = getDiffArray(words[0]);
        vector<int> diff1 = getDiffArray(words[1]);
        vector<int> diff2 = getDiffArray(words[2]);
        
        if (diff0 == diff1 && diff0 != diff2) {
            return words[2];
        } else if (diff0 == diff2 && diff0 != diff1) {
            return words[1];
        } else if (diff1 == diff2 && diff1 != diff0) {
            return words[0];
        } else {
            for (int i = 3; i < words.size(); i++) {
                if (getDiffArray(words[i]) != diff0) {
                    return words[i];
                }
            }
        }
        
        return "";
    }
};