// https://leetcode.cn/problems/reverse-integer/?envType=problem-list-v2&envId=math
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class Solution {
public:
   int reverse(int x) {
       int ans = 0;
       while (x != 0) {
           if (ans > INT32_MAX / 10 || ans < INT32_MIN / 10) return 0;
           int a = x % 10;
           ans = 10 * ans + a;
           x /= 10;
       }
       return ans;
   }
};