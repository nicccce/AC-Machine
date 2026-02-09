#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    string largestGoodInteger(string num) {
        string result = "";
        for (int i = 0; i <= (int)num.length() - 3; i++) {
            if (num[i] == num[i+1] && num[i+1] == num[i+2]) {
                string candidate = num.substr(i, 3);
                if (result == "" || candidate > result) {
                    result = candidate;
                }
            }
        }
        return result;
    }
};