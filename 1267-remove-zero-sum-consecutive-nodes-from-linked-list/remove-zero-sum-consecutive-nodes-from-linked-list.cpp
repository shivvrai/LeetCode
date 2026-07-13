class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        unordered_map<int, ListNode*> mp;

        int prefix = 0;
        ListNode* curr = dummy;

        // First pass: store last occurrence of every prefix sum
        while (curr) {
            prefix += curr->val;
            mp[prefix] = curr;
            curr = curr->next;
        }

        // Second pass: remove zero-sum sublists
        prefix = 0;
        curr = dummy;

        while (curr) {
            prefix += curr->val;
            curr->next = mp[prefix]->next;
            curr = curr->next;
        }

        return dummy->next;
    }
};