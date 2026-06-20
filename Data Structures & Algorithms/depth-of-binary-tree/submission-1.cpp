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
    int depth(TreeNode* node , int dp)
    {
        if(node == nullptr) return dp ;
        dp++ ;
        return max (depth(node->left , dp), depth (node->right , dp)); 
    }
    int maxDepth(TreeNode* root) {
        return depth(root , 0) ; 
    }
};
