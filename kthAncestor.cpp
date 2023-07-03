
// your task is to complete this function
Node* solve(Node *root, int &k, int node){
    if(root == NULL){
        return NULL;
        
    }
    if(root ->data == node){
        return root;
    }
    
    Node* left = solve(root->left, k, node);
    Node* right = solve(root->right, k, node);
    
    if(left !=NULL && right == NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return left;
    }
    if(right !=NULL && left == NULL){
        k--;
        if(k<=0){
            k=INT_MAX;
            return root;
        }
        return right;
    }
    return NULL;
}


int kthAncestor(Node *root, int k, int node)
{
    // Code here
    Node* ans = solve(root, k, node);
    if(ans == NULL || root->data == node){
        return -1;
    }
    return ans->data;
}
