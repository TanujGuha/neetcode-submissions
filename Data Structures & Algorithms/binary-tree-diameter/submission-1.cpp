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
    set <int> heights ; 
    int ans = 0 ; 
    int height(TreeNode* node)
    {
        if (node == nullptr) return 0 ; 

        int l = height(node->left) ;
        int r = height(node->right) ;


        return max(l,r) + 1 ; 
    }
    void traverse(TreeNode* node)
    {
        if (node == nullptr) return ; 

        int l = height(node->left)  ; 
        int r = height(node->right) ; 

        ans = max(ans ,  l+r) ;
        traverse(node->left) ; 
        traverse(node->right) ; 
    }
    int diameterOfBinaryTree(TreeNode* root) {
        traverse(root) ;
        return ans; 
        
    }
};
