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
    bool greater(TreeNode* node , int v)
    {
        if (!node) return true ; 
        if (node->val <= v) return false;
        
        return greater(node->left , v) &&  greater(node->right , v) ; 
    }

    bool lesser(TreeNode* node , int v)
    {
        if (!node) return true ; 
        if (node->val >= v) return false;
        
        return lesser(node->left , v) &&  lesser(node->right , v) ; 
    }    

    bool helper(TreeNode* root)
    {
        if (!root) return true ; 

        bool a = lesser(root->left , root->val) ; 
        bool b = greater(root->right , root->val) ; 

        if (a&&b)
        {
            return helper(root->left) && helper(root->right) ; 
        }
        return false ; 
    }


    bool isValidBST(TreeNode* root) {
        return helper(root) ; 
    }
};
