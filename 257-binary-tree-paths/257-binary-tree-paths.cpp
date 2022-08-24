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
//     vector<string>path(TreeNode* root, vector<string>&v){
//         if(!root) return;
//         if(!root->left||!root->right){
//             temp=temp+ to_string(root->val)+ "->";
//         }
//     }
//     vector<string> binaryTreePaths(TreeNode* root) {
//         vector<string>v;
//         vector<stirng>temp;
//         path(root,v);
//         return v;
        
        
//     }
       void DFS(TreeNode* root,string str,vector<string> &ans)
    {
        if(!(root->left) && !(root->right))
        {
            str=str + to_string(root->val);
            ans.push_back(str);
            return;
        }
        str=str + to_string(root->val)+"->";
        if(root->left)
        DFS(root->left,str,ans);
        if(root->right)
        DFS(root->right,str,ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root) return ans;
        DFS(root,"",ans);
        return ans;
    }
};