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
    vector<int> res;
    void solve(TreeNode* root, int dep) {
        if(!root) return ;

        if(res.size() == dep) {
            res.push_back(root->val);
        }

        solve(root->right, dep + 1);
        solve(root->left, dep + 1);
    }
    vector<int> rightSideView(TreeNode* root) {
        solve(root, 0);
        return res;

    }
};
