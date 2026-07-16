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
    int goodNodes(TreeNode* root) {
        queue<pair<TreeNode*, int>> que;
        que.push({root, -INT_MAX});
        int ans = 0;
        while(!que.empty()) {
            TreeNode* currNode = que.front().first;
            int maxV = que.front().second;
            que.pop();
            if(currNode->val >= maxV) {
                maxV = currNode->val;
                ans++;
            }

            if(currNode->left){
                que.push({currNode->left, max(currNode->val, maxV)});
            }
            if(currNode->right) {
                que.push({currNode->right, max(currNode->val, maxV)});
            }
        }
        return ans;
    }
};
