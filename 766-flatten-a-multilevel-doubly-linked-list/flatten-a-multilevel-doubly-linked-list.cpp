/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* curr=head;
        while(curr){
            if(curr->child){
                Node* next=curr->next;
                curr->next=flatten(curr->child);
                curr->child=nullptr;
                curr->next->prev=curr;
                Node* temp=curr;

                while(temp->next){
                    temp=temp->next;
                }
                temp->next=next;
                if(next)next->prev=temp;


            }
            else {
                curr=curr->next;
            }
        }
        return head;
    }
};