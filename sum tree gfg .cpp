
/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution
{
    private:
    pair<bool, int> isSumTreeFast(Node* root){
        if(root == NULL) {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }
        // leaf node
        if(root->left == NULL && root->right == NULL) {
            pair<bool, int> p = make_pair(true, root->data);
            return p;
        }
        pair<bool, int> leftAns = isSumTreeFast(root->left);
        pair<bool, int> rightAns = isSumTreeFast(root->right);
        
        bool isLeftSumTree = leftAns.first;
        bool isRightSumTree = rightAns.first;
        
        int leftSum = leftAns.second;
        int rightSum = rightAns.second;
        
        bool cond = root->data == (leftSum+rightSum);
        
        pair<bool, int> ans;
        if(cond && isLeftSumTree && isRightSumTree){
            ans.first = true;
            ans.second = 2*root->data;
        }
        else{
            ans.first = false;
        }
        return ans;

        
    }
    public:
    bool isSumTree(Node* root)
    {
        return isSumTreeFast(root).first;
         
    }
};
