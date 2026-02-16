// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char> st;
        for (char c : sentence) {
            st.insert(c);
        }
        return st.size() == 26;
    }
};