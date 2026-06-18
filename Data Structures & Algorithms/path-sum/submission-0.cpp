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

    bool found = false ; 
    int path(TreeNode * node , int tar , int run)
    {
        if (node == nullptr) return 0 ; 
        if (node->val + run == tar && node->left ==nullptr && node->right == nullptr)
        {
            found = true ; 
            return-1 ; 
        } 

        int c1 = path(node->left , tar , run + node->val) ; 
        if (c1 ==-1)
        {
            return-1; 
        }
        int c2 = path(node->right,  tar , run + node->val) ; 
        if (c2 == -1)
        {
            return -1 ; 
        }
        return 0 ;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        path(root , targetSum , 0) ; 
        if (found) return true ; 
        return false ;
    }
};