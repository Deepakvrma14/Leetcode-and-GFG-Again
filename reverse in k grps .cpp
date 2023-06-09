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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k==1){
            return head;
        }
        ListNode* nxt = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;

        if(!possible(head,k)){
            return head;
        }
        int count =0;
        while(count<k){
            count ++;
            nxt = curr->next;
            curr->next = prev;
            prev  = curr;
            curr = nxt;
            if(curr == NULL){
                return prev;
            }

        }

        head->next = reverseKGroup(nxt,k);
        
        return prev;
    }
    bool possible(ListNode* head, int counter){
        int length=0;
        ListNode* temp = head;
        while(temp!= NULL){
            temp = temp->next;
            length ++;

            if(length>=counter){
                return true;
            }
        }
        return false;
    }
    
};
