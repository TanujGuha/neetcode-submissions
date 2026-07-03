class Solution {
public:
    // Helper function to reverse a specific segment
    // Returns the new head of this reversed segment
    ListNode* reverse(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while (k > 0 && curr != nullptr) {
            ListNode* next_node = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_node;
            k--;
        }
        return prev; // 'prev' is the new head of the reversed segment
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Dummy node helps us manage the head smoothly
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* groupPrev = dummy;

        while (true) {
            // 1. Check if there are at least k nodes left
            ListNode* kth = groupPrev;
            for (int i = 0; i < k; i++) {
                kth = kth->next;
                if (!kth) {
                    // Less than k nodes left, leave them as they are
                    ListNode* result = dummy->next;
                    delete dummy;
                    return result;
                }
            }

            // 2. Keep track of the node right after this group
            ListNode* groupNext = kth->next;

            // 3. Reverse the current group of k nodes
            ListNode* groupStart = groupPrev->next;
            // Unlink temporarily or just reverse up to k nodes
            ListNode* newGroupHead = reverse(groupStart, k);

            // 4. Reconnect the reversed group back into the main list
            groupPrev->next = newGroupHead;
            groupStart->next = groupNext; // groupStart is now the tail of this reversed segment

            // 5. Move groupPrev to the end of the newly reversed group
            groupPrev = groupStart;
        }
    }
};