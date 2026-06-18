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
    int dia = 0 ; 
    int md(TreeNode* node)
    {
        if (node == nullptr) return 0 ;
        int l = md(node->left) ; 
        int r = md(node->right) ; 

        dia = max(dia , l + r) ; 

        return 1 + max(l , r) ;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        md(root) ;
        return dia ; 
    }
};
