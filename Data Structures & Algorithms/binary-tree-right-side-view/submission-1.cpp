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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode* > que;
        que.push(root);
        vector<int> ans;
        while(!que.empty()) {
            int size = que.size();
            TreeNode* rightSide = NULL;
            while(size--) {
                TreeNode* curr = que.front();
                que.pop();

                if(curr) {
                    rightSide = curr;

                if(curr->left) que.push(curr->left);
                if(curr->right) que.push(curr->right);
                }
            }
            if(rightSide) {
                ans.push_back(rightSide->val);
            }
        }
        return ans;
    }
};
