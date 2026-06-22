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

    int tot_sum = 0 ; 
    void cs(TreeNode* node , int curr_s)
    {
        curr_s= curr_s*10 + node->val ; 

        if (!node->left && !node->right) tot_sum += curr_s ; 
        if (node->left) cs(node->left , curr_s) ; 
        if (node->right) cs(node->right , curr_s) ; 

    }
    int sumNumbers(TreeNode* root) {
        if(!root) return 0 ; 
        cs(root , 0) ; 
        return tot_sum ;
    }
};