// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        // 计算平均值
        double sum = 0;
        for (int num : nums) {
            sum += num;
        }
        double avg = sum / nums.size();
        
        // 将数组元素放入集合中，便于查找
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        // 从平均值的下一个整数开始查找
        int start = (int)avg + 1;
        if (avg == (int)avg) {
            start = (int)avg + 1;  // 如果平均值是整数，从下一个开始
        } else {
            start = (int)ceil(avg);  // 如果平均值不是整数，从上取整开始
        }
        
        // 找到大于平均值的最小未出现正整数
        for (int i = start; ; i++) {
            if (i > 0 && numSet.find(i) == numSet.end()) {
                return i;
            }
        }
        
        return -1;  // 不会执行到这里
    }
};

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

int ex_gcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    else
    {
        int d = ex_gcd(b, a % b, y, x);
        y -= a / b * x;
        return d;
    }
}

int solve_linear_congruence_equation(int a, int b, int n)
{
    int x, y;
    int d = ex_gcd(a, n, x, y);
    if (b % d)
        return -1;
    n /= d;
    return ((long long)x * (b / d) % n + n) % n;
}