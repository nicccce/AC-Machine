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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int size = q.size();
            bool foundX = false;
            bool foundY = false;
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if (node->val == x) foundX = true;
                if (node->val == y) foundY = true;
                
                // Check if x and y are siblings (same parent)
                if (node->left && node->right) {
                    if ((node->left->val == x && node->right->val == y) ||
                        (node->left->val == y && node->right->val == x)) {
                        return false; // Same parent, not cousins
                    }
                }
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            // If both x and y are found at this level, they are cousins
            if (foundX && foundY) return true;
            // If only one of them is found at this level, they are not cousins
            if (foundX || foundY) return false;
        }
        
        return false;
    }
};