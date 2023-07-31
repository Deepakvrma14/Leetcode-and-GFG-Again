brute force 

take the root node and find target - root node if that existes, return that silution exixts else return false ;

this is only when solution is needed to be o(n^2) time else use below approach 

1. find the inorder as inroder is sorted in bst 
2. after inorder, use 2 paointers at sart and at end and traverse and save to sum 
3. if sum not equal, and is greater, ++ the end pointer as this will decrease thevalue and if value need to be higher, inclrease the start pointer 

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void in(vector<int> &ans, TreeNode* root){
        if(root == NULL){
            return;
        }
        in(ans, root->left);
        ans.push_back(root->val);
        in(ans, root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder ;
        in(inorder, root);
        int start =0;
        
        int end = inorder.size()-1;
        while(start<end){
            if((inorder[start] + inorder[end]) == k){
                return true;
            }
            if((inorder[start] + inorder[end]) <k ){
                start ++;
            }else{
                end--;
            }

        }
    return false;
    }
};
