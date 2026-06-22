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
    int flag = 0 ;
    vector <vector <int>> ans ; 
    void zigzag(queue<TreeNode*> &q , vector <vector <int>> &ans)
    {
        
        

        while(!q.empty())
        {
            int l = q.size() ; 
            vector <int> temp ; 
            for (int i = 0 ; i < l ; i++)
            {
                auto ptr = q.front() ; 
                q.pop() ; 
                temp.push_back(ptr->val) ;

                if (ptr->left) q.push(ptr->left) ; 
                if (ptr->right) q.push(ptr->right) ;
            }

            if (!flag) // keep order
            {
                ans.push_back(temp); 
            }
            else
            {
                reverse(temp.begin() , temp.end()) ; 
                ans.push_back(temp) ; 
            }
            flag = (flag+1)%2 ; 
        }

    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if (!root) return ans ; 
        queue<TreeNode*> st ; 
        st.push(root) ;
        zigzag(st ,ans) ;
        return  ans ;

    }
};