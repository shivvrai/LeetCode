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
        if(head==NULL)return head;
        Node* curr=head;
        while(curr){
            if(curr->child!=NULL){
                Node* next=curr->next;
                Node* childs=flatten(curr->child);
                curr->next=childs;
                childs->prev=curr;
                
                curr->child=NULL;
                Node* temp = childs;
                while(temp->next!=NULL){
                    temp = temp->next;
                }
                temp->next=next;
                if(next)next->prev=temp;

                curr=next;

            }
            else 
            curr=curr->next;
        }
        return head;
    }
};