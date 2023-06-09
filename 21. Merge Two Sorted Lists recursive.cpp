recursive and easist approact only 
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        return merge(list1,list2);
        //     return solve(list1, list2);
        // }
        // else{
        //     return solve(list2, list1);
        // }
    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        if(l1 == NULL){
            return l2;
        }
        if(l2 == NULL){
            return l1;
        }
        if(l1->val<l2->val){
            (l1->next = merge(l1->next, l2));
            return l1;
        }
        else{
             (l2->next  = merge(l1, l2->next));
             return l2;
        }
    }
    ListNode* solve(ListNode* first,ListNode* second){
//         if only one item is there
        if(first->next == NULL ){
            first->next  = second;
            return first;
        }
        if(second->next == NULL){
            second->next = first;
            return second ;
        }
        
        //declaration of required pointers
        ListNode* curr1 = first;
        ListNode* next1 = curr1->next;
        ListNode* curr2 = second;
        ListNode* next2 = curr2->next;


        while(next1 !=NULL && curr2 !=NULL){
            // checking main condition if 2nd ka first vala lie in between of curr1 and next1 or not to be inserted 
            if(curr1->val <= curr2->val && next1->val>=curr2->val){
                //transferring node in between 
                curr1->next = curr2;
                next2 = curr2->next;
                curr2->next  = next1;
                
                // maintaining pointers
                curr1= curr2;
                curr2 = next2;

            }
            else{
                curr1 = curr1->next;
                next1 = next1->next;
}
                if(next1 == NULL){
                    curr1->next = curr2;
                    return first;
                }
            
        }
        return first;        
    }
};
