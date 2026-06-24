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
class BSTIterator {
public:

    stack <TreeNode*> st ;
    BSTIterator(TreeNode* root) {
        while(root )
        {
            st.push(root) ; 
            if (root->left)
            {
                root= root->left ; 
            }
            else
            {
                break ; 
            }
        }
    }
    
    int next() {
        auto t = st.top() ; 
        st.pop() ; 
        TreeNode* x = t->right ;

        while(x)
        {
            st.push(x) ;
            x = x->left ;
        } 

        return t->val ; 

        if (t->right)
        {   
            st.push(t->right) ; 
            
            if (x)
            {
                while(x)
                {
                    st.push(x) ; 
                    x = x->left ;
                }
            }
        }
        st.pop() ;
        return t->val ; 
    }
    
    bool hasNext() {
        if (st.empty()) return false ; 
        return true ; 
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */