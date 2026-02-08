// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;
        
        for (string op : operations) {
            if (op == "+") {
                // New score is the sum of the previous two scores
                int newScore = scores[scores.size()-1] + scores[scores.size()-2];
                scores.push_back(newScore);
            } else if (op == "D") {
                // New score is double the previous score
                int newScore = 2 * scores[scores.size()-1];
                scores.push_back(newScore);
            } else if (op == "C") {
                // Remove the previous score
                scores.pop_back();
            } else {
                // Integer score
                scores.push_back(stoi(op));
            }
        }
        
        int total = 0;
        for (int score : scores) {
            total += score;
        }
        
        return total;
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