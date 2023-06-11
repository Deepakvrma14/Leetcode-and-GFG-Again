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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* prev = new ListNode();
        prev->next = head;
        ListNode* temp = prev;
        while(temp->next != NULL && temp -> next -> next !=NULL){
            if(temp->next->val == temp->next->next->val ){
                int variable = temp->next->val;
                while( temp->next!=NULL && temp->next->val == variable){
                    temp->next = temp->next->next;
                }
                
            }else{
                temp = temp->next;
            }
        }
        return prev->next;
    }
};
