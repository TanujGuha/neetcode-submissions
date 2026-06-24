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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue <TreeNode*> q ; 
        q.push(root) ; 

        string s = "" ; 
        vector <int> ans ; 
        while(!q.empty())
        {
            int l = q.size() ; 

            for (int i = 0 ; i < l ; i++)
            {
                TreeNode* top = q.front() ; 
                q.pop() ; 
                if (top)
                {
                    // s = s + to_string(top->val) ; 
                    // s = s + ',' ; 
                    ans.push_back(top->val) ; 
                    q.push(top->left) ; 
                    q.push(top->right) ; 
                }
                else
                {
                    // s = s + "null" ;
                    // s = s + ','; 
                    ans.push_back(INT_MIN) ; 
                }
            }
        }

        for (int i : ans)
        {
            if (i == INT_MIN)
            {
                s += "null," ;
            }
            else
            {
                s += to_string(i) ; 
                s += ',' ; 
            }

        }
        s.pop_back() ;  


        return s ;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector <int> ans ; 


        stringstream ss(data) ; 
        string token ; 
        while(getline(ss , token , ','))
        {
            if (token == "null")
            {
                ans.push_back(INT_MIN) ; 
            }
            else
            {
                ans.push_back(stoi(token)) ; 
            }
        }

        if (ans.empty() || ans[0] == INT_MIN) return nullptr ; 


        TreeNode* root = new TreeNode(ans[0]) ; 
        queue <TreeNode*> q ; 
        q.push(root) ; 
        int c = 1 ;
        while(!q.empty() and c < ans.size()) 
        {
            TreeNode* top = q.front()  ;
            q.pop() ; 
            if (c < ans.size() && ans[c] != INT_MIN)
            {
                top->left = new TreeNode(ans[c]) ; 
                q.push(top->left)  ;
            }
            if (c+1 < ans.size()&& ans[c+1] != INT_MIN){
                top->right = new TreeNode(ans[c+1]) ; 
                q.push(top->right) ; 
            }
            c += 2 ; 
        }

        return root ; 
        
    }
};
