/**
 *Definition for singly-linked list.
 *struct ListNode {
 *int val;
 *ListNode * next;
 *ListNode() : val(0), next(nullptr) {}
 *ListNode(int x) : val(x), next(nullptr) {}
 *ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* reverseList(ListNode *head)
        {
            // Approach 1
            // if(head == NULL || head->next == NULL){
            //     return head;
            // }
//             ListNode* prev = NULL;
//             ListNode* curr = head;
            
            // while (curr != NULL)
            // {
            //     ListNode* frwd = curr->next;
            //     curr->next  =prev;
            //     prev = curr;
            //     curr= frwd;
            // }
            // return prev;
            
            
//             approach 2 
            // ListNode* prev = NULL;
            // ListNode* curr = head;
            // solution(head, prev, curr);
            // return head;
        
//         void solution( ListNode* &head,  ListNode* prev,  ListNode* curr){
//             if(curr == NULL){
//                 head= prev;
//                 return;
//             }
            
//             ListNode* frwd = curr->next;
//             solution(head, curr, frwd);
//             curr->next =  prev;
//         }
            // approach 3 
            return reverse1(head);
            }
        ListNode* reverse1(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* chotaHead  = reverse1(head->next);
        head -> next -> next = head;
        head->next = NULL;
        return chotaHead;
    }
};