// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        // 将日期转换为一年中的天数
        vector<int> daysInMonth = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        vector<int> prefixSum(13, 0);
        for(int i = 1; i <= 12; i++) {
            prefixSum[i] = prefixSum[i-1] + daysInMonth[i-1];
        }
        
        // 解析日期函数
        auto parseDate = [&](const string& date) -> int {
            int month = (date[0] - '0') * 10 + (date[1] - '0');
            int day = (date[3] - '0') * 10 + (date[4] - '0');
            return prefixSum[month] + day;
        };
        
        int aliceStart = parseDate(arriveAlice);
        int aliceEnd = parseDate(leaveAlice);
        int bobStart = parseDate(arriveBob);
        int bobEnd = parseDate(leaveBob);
        
        // 找到重叠区间
        int overlapStart = max(aliceStart, bobStart);
        int overlapEnd = min(aliceEnd, bobEnd);
        
        if(overlapStart > overlapEnd) {
            return 0;
        }
        
        return overlapEnd - overlapStart + 1;
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