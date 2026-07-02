class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Fixed syntax: use proper constructor parens
        ListNode* dummy = new ListNode(); 
        ListNode* cpy = dummy; 
        
        while(list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                dummy->next = list1; 
                list1 = list1->next; 
            }
            else
            {
                dummy->next = list2; 
                list2 = list2->next; 
            }
            // Move our merged list's tail forward to the newly attached node
            dummy = dummy->next; 
        }

        // Instead of a while loop, a simple if statement works perfectly here!
        // Since the rest of the list is already sorted, just link the whole thing.
        if (list1) {
            dummy->next = list1;
        } else {
            dummy->next = list2;
        }

        // Fixed syntax: added semicolon and returned ->next to skip the dummy node
        return cpy->next;
    }
};