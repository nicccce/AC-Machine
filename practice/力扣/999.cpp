// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int n = 8;
        int rookRow = -1, rookCol = -1;
        
        // 找到车的位置
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 'R') {
                    rookRow = i;
                    rookCol = j;
                    break;
                }
            }
            if(rookRow != -1) break;
        }
        
        int count = 0;
        
        // 向上移动
        for(int i = rookRow - 1; i >= 0; i--) {
            if(board[i][rookCol] == 'B') break;
            if(board[i][rookCol] == 'p') {
                count++;
                break;
            }
        }
        
        // 向下移动
        for(int i = rookRow + 1; i < n; i++) {
            if(board[i][rookCol] == 'B') break;
            if(board[i][rookCol] == 'p') {
                count++;
                break;
            }
        }
        
        // 向左移动
        for(int j = rookCol - 1; j >= 0; j--) {
            if(board[rookRow][j] == 'B') break;
            if(board[rookRow][j] == 'p') {
                count++;
                break;
            }
        }
        
        // 向右移动
        for(int j = rookCol + 1; j < n; j++) {
            if(board[rookRow][j] == 'B') break;
            if(board[rookRow][j] == 'p') {
                count++;
                break;
            }
        }
        
        return count;
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