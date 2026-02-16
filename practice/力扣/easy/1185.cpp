// 
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
                                                                                                                                                                             


/*
 * @lc app=leetcode.cn id=1185 lang=cpp
 *
 * [1185] 一周中的第几天
 */

// @lc code=start
class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> days = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        
        // 1971年1月1日是星期五，作为基准日期
        int base = 5; // 0: Sunday, 1: Monday, ..., 6: Saturday, 5: Friday
        
        // 计算从1971年到目标年份的总天数
        int daysCount = 0;
        for(int i = 1971; i < year; i++) {
            if(isLeapYear(i)) {
                daysCount += 366;
            } else {
                daysCount += 365;
            }
        }
        
        // 计算当年的累计天数
        int monthDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if(isLeapYear(year)) {
            monthDays[2] = 29; // 闰年2月29天
        }
        
        for(int i = 1; i < month; i++) {
            daysCount += monthDays[i];
        }
        daysCount += day - 1; // 当前日
        
        int result = (base + daysCount) % 7;
        return days[result];
    }
    
    bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
};
// @lc code=end