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
    // TreeNode* func(vector <int> & preorder, vector <int> &inorder , int lp , int li , int ri) ; 
    TreeNode* func(vector <int> & preorder, vector <int> &inorder , int lp , int li ,  int ri)
    {

        if(lp >= preorder.size() ||  li > ri) return nullptr ;
        if (lp < preorder.size() && li <= ri)
        {
            TreeNode* root = new TreeNode(preorder[lp]) ; 
            auto it = find(inorder.begin() + li , inorder.begin() + ri + 1, preorder[lp]) ; 
            if (it != inorder.end())
            {
                int li1 = li ; 
                int ri1 = it - inorder.begin()- 1 ; 

                int li2 = it - inorder.begin() +1 ; 
                int ri2 = ri ; 

                int ls = ri1 - li1 +1; 
                int rs = ri2 - li2 +1;

                if (ls > 0)
                {
                    root->left = func(preorder , inorder , lp + 1, li1 , ri1) ; 
                }
                if (rs > 0)
                {
                    root->right = func(preorder , inorder , lp + ls + 1 , li2 , ri2) ; 
                }

            }

            return root ; 
        }

        return nullptr ; 
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = (func(preorder , inorder , 0 , 0 , inorder.size()-1)) ; 
        return root; 
    }
};
