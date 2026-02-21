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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* oddtail = odd;
        ListNode* eventail = even;
        ListNode* temp = even->next;
        while(temp!=NULL){
            oddtail->next = temp;
            oddtail = temp;
            eventail->next = temp->next;
            eventail = temp->next;
            if(temp->next!=NULL) temp=temp->next->next;
            else break;
        }
        oddtail->next = even;
        return odd;     
    }
};