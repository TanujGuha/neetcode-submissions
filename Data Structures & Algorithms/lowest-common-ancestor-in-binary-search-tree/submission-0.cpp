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

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr ; 

        if (root->val == p->val || root->val == q->val )return root ; 

        int side1 = 0, side2 = 0; 
        int v1 = p->val ; 
        int v2 = q->val ; 

        if (v1 < root->val)
        {
            side1 = 1 ;
        } 
        if (v2 < root->val)
        {
            side2 = 1 ; 
        }

        if (side1 == side2)
        {
            if (side1 == 1)
            {
                return lowestCommonAncestor(root->left , p , q) ; 
            }
            else
            {
                return lowestCommonAncestor(root->right , p , q) ; 
            }
        }
        else{
            return root ; 
        }
    }
};
