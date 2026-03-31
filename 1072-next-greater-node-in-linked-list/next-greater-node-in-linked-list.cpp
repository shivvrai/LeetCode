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
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode *p = head;
        vector<int> ans;
        bool check;
        while(p != nullptr){
            ListNode *temp = p;
            check = false;
            while(temp != nullptr){
                if(p->val < temp->val){
                    ans.push_back(temp->val);
                    check = true;
                    break;
                }
                temp = temp -> next;
            }
            if(check == false) ans.push_back(0);
            p = p -> next;
        }
        return ans;
    }
};