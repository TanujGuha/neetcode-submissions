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
    TreeNode* prev ; 
    void iter(stack <TreeNode*> st)
    {
        while(prev || !st.empty())
        {
            while(prev)
            {
                st.push(prev) ; 
                prev = prev->left ;
            }

            prev = st.top() ; 
            st.pop() ; 

            ans.push_back(prev->val) ; 
            prev = prev->right ; 

        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        prev = root ; 
        if (root == nullptr) return ans ; 
        stack <TreeNode*> st ; 
        
        iter(st) ;
        return ans ; 

    }
};