class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr; 
        ListNode* nxt = nullptr; 
        ListNode* curr = head; 

        while(curr != nullptr)
        {   
            nxt = curr->next;    // Save the next node
            curr->next = prev;   // Reverse the current node's link
            prev = curr;         // Move prev one step forward
            curr = nxt;          // Move curr one step forward
        }

        // When curr becomes nullptr, prev is sitting right at the new head!
        return prev; 
    }
};