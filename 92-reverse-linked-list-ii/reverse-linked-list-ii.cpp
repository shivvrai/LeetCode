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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        vector <int> nodeValues;
        ListNode *ptr = head;

        while(ptr){
            nodeValues.push_back(ptr->val);
            ptr = ptr->next;
        }

        int i = 0, n = nodeValues.size();
        ptr = head;
        left--;right--;
        while(i < n && left <= right){
            if (i >= left){
                ptr->val = nodeValues[right--];
            }
            i++;
            ptr = ptr->next;
        }
        return head;
    }
};