class Solution {
public:
    TreeNode* find(TreeNode* node, int key) {
        if (node == nullptr) return nullptr; 
        
        if (node->left != nullptr && node->left->val == key) return node; 
        if (node->right != nullptr && node->right->val == key) return node;

        if (key < node->val) return find(node->left, key);
        else return find(node->right, key); 
    }

    // Pass the actual system root parameter along to keep the return layout functional
    TreeNode* del(TreeNode* root, TreeNode* node, int key) {
        // Case A: The node to delete is the LEFT child of the parent
        if (node->left != nullptr && node->left->val == key) {
            TreeNode* deleting_ele = node->left;
            TreeNode* del_right_child = deleting_ele->right; 
            TreeNode* del_left_child = deleting_ele->left; 

            if (del_right_child == nullptr) {
                node->left = del_left_child; 
                return root; 
            }
            if (del_left_child == nullptr) {
                node->left = del_right_child; 
                return root; 
            }
            
            TreeNode* rc = del_right_child;
            while (rc->left != nullptr) {
                rc = rc->left; 
            }
            rc->left = del_left_child; 
            node->left = del_right_child; // ✅ Always update the link to the parent
        }
        // Case B: The node to delete is the RIGHT child of the parent
        else if (node->right != nullptr && node->right->val == key) {
            TreeNode* deleting_ele = node->right;
            TreeNode* del_right_child = deleting_ele->right; 
            TreeNode* del_left_child = deleting_ele->left; 

            if (del_right_child == nullptr) {
                node->right = del_left_child; 
                return root; 
            }
            if (del_left_child == nullptr) {
                node->right = del_right_child; 
                return root; 
            }
            
            TreeNode* rc = del_right_child;
            while (rc->left != nullptr) {
                rc = rc->left; 
            }
            rc->left = del_left_child; 
            node->right = del_right_child; // ✅ Always update the link to the parent
        }
        return root;
    }

    TreeNode* check(TreeNode* root, int key) {
        if (root->val == key) {
            TreeNode* rv = root->right; 
            if (rv == nullptr) return root->left; 

            TreeNode* i = rv; 
            while (i->left != nullptr) {
                i = i->left; 
            }    
            i->left = root->left; 
            return rv; 
        }
        return nullptr; 
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;

        // 1. Handle Root Deletion
        if (root->val == key) {
            return check(root, key);
        }  

        // 2. Locate Parent
        TreeNode* parent = find(root, key); 
        if (parent == nullptr) return root; 
        
        // 3. Execute Grafting
        return del(root, parent, key); 
    }
};