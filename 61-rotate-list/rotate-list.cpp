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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or k ==0) return head;
        ListNode* tail=head;int len=1;
        while(tail->next){
            tail=tail->next;len++;
        }
        k=k%len;
        tail->next=head;
        int rem=len-k;
        ListNode* newtail=head;
        for(int i=1;i<rem;i++){
            newtail=newtail->next;
        }
        ListNode* newhead=newtail->next;
        newtail->next=nullptr;
        return newhead;
    }
};