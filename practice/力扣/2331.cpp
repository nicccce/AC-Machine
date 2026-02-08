// 
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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
    bool evaluateTree(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            return root->val;
        }
        
        bool left_val = evaluateTree(root->left);
        bool right_val = evaluateTree(root->right);
        
        if (root->val == 2) {
            return left_val || right_val;
        } else {
            return left_val && right_val;
        }
    }
};