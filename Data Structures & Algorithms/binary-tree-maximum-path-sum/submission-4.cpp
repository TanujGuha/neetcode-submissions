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

    int mps = INT_MIN ; 
    int mp(TreeNode* node)
    {
        if (node == nullptr) return 0 ;

        int l = max(mp(node->left), 0)  ; 
        int r = max(mp(node->right), 0) ;
        int mps1 = max({l, r , l+r}) ; 
        mps = max(mps , mps1 + node->val) ; 
        return node->val + max({l,r,  0}) ;  
        
    }
    int maxPathSum(TreeNode* root) {
        mp(root) ; 
        return mps ; 
    }
};
