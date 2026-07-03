/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr ; 
        Node* curr = head ; 

        while(curr)
        {
            Node* clone = new Node(curr->val) ;
            clone->next = curr->next ; 
            curr->next = clone ;
            curr = curr->next->next  ;
        }


        curr = head ; 

        while(curr)
        {
            if (curr->random)
            {
                curr->next->random = curr->random->next ;
            }
            curr = curr->next->next ;
        }

        // decoupling

        curr = head ; 
        Node* cloneH = curr->next ; 
        Node* copy = cloneH ; 

        while(curr)
        {
            curr->next = curr->next->next  ;
            if (copy->next) copy->next = copy->next->next ; 
            else copy->next = nullptr ; 

            curr = curr->next ; 
            copy = copy->next ;
        }

        return cloneH ; 
    }
};
