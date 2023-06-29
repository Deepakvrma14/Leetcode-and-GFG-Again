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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int ,  map<int, multiset<int> > > nodes; 
        //<!-- this will be our data structure which we will be using to store out the values , it takes value as horizontal distance, then a map to store level and a list of nodes in multi set-->
        queue<pair<TreeNode* , pair<int, int>>> q;
        //<!-- this queue will be used to itetrate and store the nodes level and horizpoontal distance in a normal way -->
        vector<vector<int> > ans; 
//<!-- our end ans which we created above only to cover case of empty root -->
        if(root == NULL){
            return ans;
        }
        <!-- this will take care of our empty root condition -->
        q.push({root,{0,0}}); 
// pushing the empty root with horizontal distance as 0 and level as 0
        while(!q.empty()){
            auto p = q.front(); 
            q.pop();
            TreeNode* node = p.first;
            //take out first node and assign horizontal distance and level for it  by below method
            int hd = p.second.first;
            int lvl = p.second.second;
            nodes[hd][lvl].insert(node->val);
// insert that first node value to the data structure which we made at first with map and assign horizontal distance and level to the value of node

            if(node->left) q.push({node->left, {hd-1,lvl+1}});
//if either of left or right exists, put that node in the queue and make sure that horizontal distance decreases in case of going left and increases in case of right and level always increases
            if(node->right) q.push({node->right, {hd+1,lvl+1}});
            
        }
// now everthing is done, just copy the elements from data structure to our desired output structure
        for(auto p:nodes){ //ititrate entire ds
            vector<int> col; // make a col which will store vertical levels
            for(auto c:p.second){ // this will ititrate throght the second map inside the ds, which is for levele and nodes which we will use to itetrate
                col.insert(col.end(), c.second.begin(), c.second.end());
// insert into the col at the end from beginnign to ending of that col size

            }
            ans.push_back(col);// inert that col into ans
        }
        return ans; // return ans
    }
};
