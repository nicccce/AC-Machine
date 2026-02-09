// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
private:
    int maxCount = 0;
    int currentCount = 0;
    int* prev = nullptr;
    vector<int> result;

public:
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return result;
    }

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        // 处理当前节点
        if (prev == nullptr || *prev != root->val) {
            currentCount = 1;
        } else {
            currentCount++;
        }

        if (currentCount > maxCount) {
            maxCount = currentCount;
            result.clear();
            result.push_back(root->val);
        } else if (currentCount == maxCount) {
            result.push_back(root->val);
        }

        prev = &(root->val);

        inorder(root->right);
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