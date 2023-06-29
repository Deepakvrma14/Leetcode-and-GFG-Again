left view.cpp

void sol(Node* root, int level, vector<int> &ans){
    if(root == NULL){
       return ;
   }
   if(level == ans.size()){
       ans.push_back(root->data);
   }
   if(root->left) sol(root->left, level+1, ans);
   if(root->right) sol(root->right, level+1, ans);
}
vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   sol(root, 0, ans);
   return ans;
}
