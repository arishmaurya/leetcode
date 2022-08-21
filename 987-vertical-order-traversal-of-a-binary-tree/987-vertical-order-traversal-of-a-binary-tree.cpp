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
        map<int,map<int,multiset<int>>>nodes;  // (node,vertical,level)
        queue<pair<TreeNode*,pair<int,int>>>todo; /// (node,vertical,level) will be inserted in queue
        todo.push({root,{0,0}});
        while(!todo.empty()){
        auto p=todo.front(); // automatically detects the data type 
            todo.pop();
            TreeNode*node= p.first;
            int x=p.second.first , y=p.second.second;
            nodes[x][y].insert(node->val);
            if(node->left) todo.push({node->left,{x-1,y+1}});
            if(node->right) todo.push({node->right,{x+1,y+1}});
        }
        
        vector<vector<int>>ans;
        for(auto p:nodes){
            vector<int>level;
            for(auto q:p.second){
                level.insert(level.end(),q.second.begin(),q.second.end());// why insert is used do a dry run why push_back is not working here
            }
            ans.push_back(level);
        }
        return ans;
    }
    

};