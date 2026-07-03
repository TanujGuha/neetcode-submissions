/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:


    ListNode* reverse(ListNode* head)
    {
        if (!head) return nullptr ;
        if (!head->next) return head ; 


        ListNode* curr = head ;
        ListNode* prev = nullptr ; 
        while(curr)
        {
            ListNode* temp = curr->next ; 
            curr->next =  prev ; 
            prev = curr ; 
            curr = temp ; 
        }

        return prev ; 
    }
    void reorderList(ListNode* head) {
        if(!head) return  ; 
        if (!head->next) return ; 

        ListNode* fast = head->next ; 
        ListNode* slow = head ; 


        while(fast && fast->next )
        {
            slow = slow->next ; 
            fast = fast->next->next  ;
        }

        ListNode* hl = head ; 
        ListNode* hr ;


        if (!fast) //  odd numbers, 
        {
            // reversing all nodes from slow->next to fast
            hr = reverse(slow->next) ;
            slow->next = nullptr ; 
            
            while(hr)
            {
                ListNode* temp_l = hl->next ; 
                ListNode* temp_r = hr->next ; 
                hl->next = hr ; 
                hr->next = temp_l ; 
                hl = temp_l ; 
                hr = temp_r ; 
            }

            slow->next = nullptr ;


            // Done
        }
        else
        {
            hr = reverse(slow->next) ; 
            slow->next = nullptr ;
            while(hl)
            {
                ListNode* temp_l = hl->next ; 
                ListNode* temp_r = hr->next ; 

                hl->next = hr ; 
                hr->next = temp_l ; 
                hl = temp_l ; 
                hr = temp_r ;
            }

            
        }

        return  ;
    }
};
