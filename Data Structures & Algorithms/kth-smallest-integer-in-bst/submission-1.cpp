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
    void fill(vector <int> &ans , int k , TreeNode* node)
    {
        if (ans.size() == k || !node)
        {
            return  ; 
        }
        fill(ans , k , node->left) ; 
        if (ans.size() == k) return  ; 
        ans.push_back(node->val) ; 
        if (ans.size() == k) return ; 
        fill(ans , k , node->right) ; 
    }
    int kthSmallest(TreeNode* root, int k) {
        fill(ans , k , root) ;
        if (ans.empty()) return -1 ;
        return ans[k-1] ;  

    }
};
