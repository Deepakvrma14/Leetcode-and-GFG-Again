/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertAtTail(Node* &ansHead, Node* &ansTail, int digit){
        Node* temp = new Node(digit);
        if(ansHead== NULL){
            ansHead = temp;
            ansTail = temp;
            return;
        }
        else{
            ansTail->next = temp;
            ansTail = temp;
        }
    }
    Node* copyRandomList(Node* head) {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;
        while(temp != NULL){
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }
        unordered_map<Node*,Node*> oldtonew;
        Node* originalNode = head;
        Node* cloneNode = cloneHead;

        while(originalNode!= NULL){
            oldtonew[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode=cloneNode->next;
        }
        originalNode = head;
        cloneNode = cloneHead;

        while(originalNode!=NULL){
            cloneNode->random = oldtonew[originalNode->random];
            cloneNode = cloneNode->next;
            originalNode = originalNode->next;
        }
        return cloneHead;
    }
};
