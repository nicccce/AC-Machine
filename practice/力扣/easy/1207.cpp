// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for (int x : arr) {
            cnt[x]++;
        }
        
        unordered_set<int> occurrences;
        for (auto& [num, freq] : cnt) {
            if (occurrences.count(freq)) {
                return false;
            }
            occurrences.insert(freq);
        }
        
        return true;
    }
};