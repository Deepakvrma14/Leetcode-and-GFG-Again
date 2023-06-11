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
    ListNode* reverse(ListNode* &head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nxt = NULL;
        while(curr!=NULL){
            nxt = curr->next;
            curr ->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    void insertAtTail(ListNode* &ansHead, ListNode* &ansTail, int digit){
        ListNode* temp = new ListNode(digit);
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
    ListNode* addNodes(ListNode* first, ListNode* second){
        int carry = 0;
        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;

        while(first!=NULL && second !=NULL){
            int sum = carry + first->val+ second->val;
            int digit = sum %10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum/10;
            first = first->next;
            second = second->next;
        }
        while(first!=NULL){
            int sum = carry + first->val;
            int digit = sum %10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum/10;
            first = first->next;

        }
        while(second!=NULL){
            int sum = carry + second->val;
            int digit = sum %10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum/10;
            second = second->next;

        }
        while(carry!=0){
            int sum = carry;
            int digit = sum %10;
            insertAtTail(ansHead, ansTail, digit);
            carry = sum/10;
        }
        return ansHead;

    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* first = reverse(l1);

        ListNode* second = reverse(l2);

        ListNode* ans = addNodes(first, second);
        // ans = reverse(ans);
        return ans;

        
    }
};


Input
l1 =
[2,4,9]
l2 =
[5,6,4,9]
Use Testcase
Output
[8,9,8,5]
Expected
[7,0,4,0,1]
