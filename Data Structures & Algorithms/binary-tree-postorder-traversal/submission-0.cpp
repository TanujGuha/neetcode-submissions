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
    vector <int> post ; 
    void po(stack<TreeNode*> &s1 ,stack<TreeNode*> &s2 )
    {
        while(!s1.empty())
        {
            TreeNode* t = s1.top() ; 
            s1.pop() ; 
            s2.push(t) ; 

            if (t->left) s1.push(t->left) ;
            if (t->right) s1.push(t->right) ;
        }


        while(!s2.empty())
        {
            post.push_back(s2.top()->val) ; 
            s2.pop() ; 
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return post ; 
        stack <TreeNode*> s1 , s2 ;  
        s1.push(root) ;
        po(s1 ,  s2) ; 
        return post ;

    }
};