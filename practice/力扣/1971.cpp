// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;
        
        // 构建邻接表
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        // BFS搜索
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    if (neighbor == destination) {
                        return true;
                    }
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        
        return false;
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