#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll qpow(ll b, ll p, ll mod)
{
    ll r = 1;
    while (p)
    {
        if (p & 1)
            r = r * b % mod;
        b = b * b % mod, p >>= 1;
    }
    return r;
}

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        // 统计chars中每个字符的出现次数
        vector<int> charCount(26, 0);
        for (char c : chars) {
            charCount[c - 'a']++;
        }
        
        int result = 0;
        
        // 遍历每个单词
        for (string word : words) {
            // 统计当前单词每个字符的出现次数
            vector<int> wordCount(26, 0);
            for (char c : word) {
                wordCount[c - 'a']++;
            }
            
            // 检查是否可以使用chars中的字符拼出当前单词
            bool canForm = true;
            for (int i = 0; i < 26; i++) {
                if (wordCount[i] > charCount[i]) {
                    canForm = false;
                    break;
                }
            }
            
            if (canForm) {
                result += word.length();
            }
        }
        
        return result;
    }
};