// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        return abs(getDays(date1) - getDays(date2));
    }
    
private:
    bool isLeap(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
    
    int getDays(string date) {
        int year, month, day;
        sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
        
        int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int totalDays = 0;
        
        // Add days for complete years
        for (int y = 1971; y < year; y++) {
            totalDays += isLeap(y) ? 366 : 365;
        }
        
        // Add days for complete months in the current year
        for (int m = 1; m < month; m++) {
            totalDays += daysInMonth[m];
            if (m == 2 && isLeap(year)) {
                totalDays++; // Add leap day
            }
        }
        
        // Add remaining days
        totalDays += day;
        
        return totalDays;
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