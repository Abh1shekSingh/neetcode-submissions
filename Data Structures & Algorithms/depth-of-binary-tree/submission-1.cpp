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
    int maxDepth(TreeNode* root) {
        /*
        {DFS}

        if(!root) return 0;
        stack<pair<TreeNode*, int>> st;

        st.push({root, 1}); 
        int res = 0;
        while(!st.empty()) {
            TreeNode* node = st.top().first;
            int depth = st.top().second;
            st.pop();
            res = max(res, depth);

            if(node->left) st.push({node->left, depth + 1});
            if(node->right) st.push({node->right, depth + 1});
        }
        return res;
        */

        /*BFS*/
        if(!root) return 0;
        queue<TreeNode*> que;

        que.push(root);
        int level = 0;
        while(!que.empty()) {
            int size = que.size();
            while(size--) {
                TreeNode* node = que.front();
                que.pop();

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            level++;
        }
        return level;
    }
};
