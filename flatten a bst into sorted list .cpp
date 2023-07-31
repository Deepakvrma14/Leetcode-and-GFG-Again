1. find inordder, 
  2. create a new node
3. for that node, first make its left NULL and right pointing to next vector value of inorder 
4. point last right to null as well


void in(vector<int> &ans, TreeNode<int>* root){
        if(root == NULL){
            return;
        }
        in(ans, root->left);
        ans.push_back(root->data);
        in(ans, root->right);
    }
TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    vector<int> ino;
    in(ino, root);
    TreeNode<int>* ans = new TreeNode<int>(ino[0]);
    TreeNode<int>* temp = ans;
    for (int i  = 1; i< ino.size();i++){
        TreeNode<int>* node = new TreeNode<int>(ino[i]);
        temp->left =  NULL;
        temp->right = node;
        temp = node;
    }
    temp->left = NULL;
    temp->right = NULL;
    return ans;


}
