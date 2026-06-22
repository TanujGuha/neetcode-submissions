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

    vector <int> ans ; 
    void right(TreeNode* node , queue<TreeNode*> q)
    {
        if (!node) return;

        while(!q.empty())
        {
            int l = q.size() ;
            for (int i = 0 ; i < l ; i++)
            {
                auto it = q.front() ; 
                q.pop() ; 
                if (i == l-1)
                {
                    ans.push_back(it->val) ; 
                }

                if (it->left) q.push(it->left) ; 
                if (it->right) q.push(it->right) ; 
            } 

        }

    }
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return ans ; 
        queue<TreeNode*> q ;
        q.push(root) ; 
        right(root , q) ; 
        return ans;
    }
};
