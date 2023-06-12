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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //base case
        if(head == NULL || (head->next ==NULL && n == 1)){
            return NULL;
        }
        int count = 0 ;
        ListNode* temp = head;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }if(count == n){
            ListNode* tempp = head->next;
            head = tempp;
            return head;
        }else{
        count =  count-n-1;

        }
        temp = head;
        while(temp!=NULL&&count!=0){
            temp = temp->next;
            count--;
        }
        
        temp->next = temp->next->next;
        
        temp = head;
        return temp;
    }
};
