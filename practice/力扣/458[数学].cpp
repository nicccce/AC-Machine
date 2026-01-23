// https://leetcode.cn/problems/poor-pigs/description/?envType=problem-list-v2&envId=math
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int n=minutesToTest/minutesToDie+1,x=ceil(log(buckets)/log(n));
        return pow(n,x-1)<buckets?x:x-1;
    }
};