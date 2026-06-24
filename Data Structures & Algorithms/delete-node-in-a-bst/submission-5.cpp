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

    TreeNode* find_parent(TreeNode* root , int tar)
    {
        if (!root) return nullptr ; 
        if (root->left && root->left->val == tar) return root ; 
        if (root->right && root->right->val == tar) return root ;

        if (root->val > tar)
        {
            return find_parent(root->left , tar) ; 
        } 
        else{
            return find_parent(root->right , tar) ; 
        }

    }
    void del_node(TreeNode* root , int key ){

        
        TreeNode* target ;
        TreeNode* parent = root;
        int dir = 0 ; 
        if (root->left && root->left->val == key)
        {
            target = root->left;  
            dir = 1 ; 
        }
        else
        {
            target = root->right ; 
        }

        // target contains the element to delete
        // parent contains 'targets' parent.

        if (!target->left &&  !target->right){
            if (dir == 1)
            {
                root->left = nullptr ; 
                return; 
            }
            else
            {
                root->right = nullptr ; 
                return ; 
            }
        } //  no children

        if (!target->left || !target->right) // one child
        {
            if (target->left)
            {
                if (dir == 1)
                {
                    parent->left = target->left ; 
                    return ; 
                }
                else
                {
                    parent->right = target->left ; 
                    return ;
                }
            }
            else 
            {
                if (dir == 1)
                {
                    parent->left = target->right ; 
                    return ; 
                }
                else
                {
                    parent->right = target->right ; 
                    return  ; 
                }                
            }
        }

        // two children 

        TreeNode* l = target->left ; 
        TreeNode* r = target->right ;
        if (l)
        {
            while(l->right != nullptr)
            {
                l = l->right ; 
            }
            l->right = target->right ; 
            if (dir == 1)
            {
                parent->left = target->left ;
            }
            else
            {
                parent->right = target->left ; 
            }

            return ;
        }
        else
        {
            while(r->left != nullptr)
            {
                l = l->left ; 
            }
            l->left = target->left ; 
            if (dir == 1)
            {
                parent->left = target->right ;
            }
            else
            {
                parent->right = target->right ; 
            }

            return ;            
        }
    }

    TreeNode* special(TreeNode* root)
    {
        TreeNode* lc = root->left ; 
        TreeNode* rc = root->right ; 

        if (!lc && !rc) return nullptr ; 
        if (!lc && rc)
        {
            return rc ;
        }
        if (lc && !rc)
        {
            return lc ; 
        }

        TreeNode* rk = lc->right ; 
        if(!rk)
        {
            lc->right = rc ; 
            return lc ; 
        }
        while(rk->right != nullptr)
        {
            rk = rk->right ; 
        }
        rk->right  = rc ;
        return lc ; 
    }


    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr  ;
        if (root->val == key) 
        {
            return special(root) ; 
        }
        TreeNode* parent = find_parent(root , key) ;
        if (!parent) return root ; 
        del_node(parent , key) ;  
        return root ; 

    }
};