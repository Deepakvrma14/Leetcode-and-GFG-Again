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
        return solution(head);
        
    }
    ListNode* solution(ListNode* &head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* temp = head;
        while(temp->next!=NULL){
            if(temp->val  == temp->next->val){
                temp->next = temp->next->next;
            }
            else{
                temp= temp->next;
            }
        }
        return head;
       
        
    }
};

just check if head ka vlaue is same as uske next ka value .. if so then skip it else normally travverse using an temp so that only the things which are gonna 
be deleted that nonly et changed ... keep head at the front in short and itettate and make continuous changes using the temp  variable
