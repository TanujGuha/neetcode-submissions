/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:


    bool found(TreeNode* node , TreeNode* ele)
    {   
        if (node == ele) return true ; 
        if (!node) return false ; 


        return found(node->left , ele) || found(node->right , ele) ; 
    }

    TreeNode* trav(TreeNode* node, TreeNode* p , TreeNode* q)
    {

        if (node == p ) return p ;
        if (node == q) return q ; 
        bool f1 = found(node->left , p) ; 
        bool f2 = found(node->left , q) ; 
        bool f3 = found(node->right , p) ;
        bool f4 = found(node->right , q) ;

        if ((f1&&f4) || (f2&&f3)) return node;
        if(f1 && f2) return trav(node->left ,p , q) ; 
        if (f3 && f4) return trav(node->right , p , q) ;  
        else
        {

        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return trav(root , p , q) ;
    }
};