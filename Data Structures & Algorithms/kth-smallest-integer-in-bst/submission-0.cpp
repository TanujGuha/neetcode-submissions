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
    vector<int> seq ; 

    void in(TreeNode* node , vector<int> &seq , vector <int> &ans , int k)
    {
        if (!ans.empty()) return ; 
        if (node == nullptr) return  ; 

        in(node->left , seq, ans , k) ; 
        if (!ans.empty()) return ;
        if (seq.size() == k)
        {
            ans.push_back(seq.back()) ; 
            return ; 
        }
        seq.push_back(node->val) ; 
        if (!ans.empty()) return ;
        if (seq.size() == k){
            ans.push_back(seq.back()) ; 
            return ; 
        }

        in(node->right , seq , ans , k ) ;
        if (!ans.empty()) return ;
        if (seq.size() == k)
        {
            ans.push_back(seq.back()) ; 
            return ; 
        }

        return ; 
    }


    int kthSmallest(TreeNode* root, int k) {
        in(root , seq , ans , k) ;
        return ans[0] ; 
    }
};
