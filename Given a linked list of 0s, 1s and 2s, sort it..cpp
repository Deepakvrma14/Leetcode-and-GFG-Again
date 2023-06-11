//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    void insertAtTail(Node* &tail, int data){
        Node* curr = new Node(data);
        tail->next = curr;
        tail = curr;
        
    }
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        Node* zerohead = new Node(-1);
        Node* onehead = new Node(-1);
        Node* twohead = new Node(-1);
        Node* zeroTail = zerohead;
        Node* oneTail =onehead;
        Node* twoTail = twohead;
        
        Node* curr = head;
        
        while(curr!=NULL){
            if(curr->data == 0){
                insertAtTail(zeroTail, 0);
            } else if(curr->data == 1){
                insertAtTail(oneTail, 1);
            } else{
                insertAtTail(twoTail,2);
            }
            curr= curr->next;
            
        }
        
        //merge 
        // if(zerohead->next==NULL && onehead->next == NULL){
        //     return twohead->next;
        // }
        // // if()
        // if(onehead->next !=NULL){
        //     zeroTail->next = onehead->next;
        // }
        // else if(onehead->next == NULL){
        //     zeroTail->next == twohead->next;
        //     return zerohead->next;
        // }
        // oneTail->next  = twohead->next;
        // twoTail->next = NULL;
        
        // head = zerohead->next;
        // return head;
        oneTail->next = twohead->next;
        zeroTail->next = onehead->next;
        return zerohead->next;
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends
