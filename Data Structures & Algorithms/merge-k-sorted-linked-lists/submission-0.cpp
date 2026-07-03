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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue< pair<int , ListNode*> , vector<pair<int , ListNode*>> , greater<pair<int , ListNode*>>> pq ; 

        for (auto it : lists)
        {
            ListNode* curr = it ; 

            while(curr)
            {
                pq.push({curr->val , curr}) ; 
                curr = curr->next ;
            }
        }

        ListNode dummy(0) ; 
        ListNode* tail = &dummy ;
        while(!pq.empty())
        {
            auto it = pq.top() ; 
            pq.pop() ; 
            tail->next = it.second ; 
            tail = tail->next ; 

        }
        tail->next = nullptr ;
        return dummy.next ; 
    }
};
