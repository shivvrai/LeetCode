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
struct cmp {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;   
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        for(int i=0;i<k;i++){if(lists[i])pq.push(lists[i]);}
        ListNode* dummy=new ListNode(0);ListNode* curr=dummy;
        while(!pq.empty()){
            ListNode* node=pq.top();
            pq.pop();
            curr->next=node;
            curr=node;
            if(node->next)pq.push(node->next);
        }
        return dummy->next;
    }
};