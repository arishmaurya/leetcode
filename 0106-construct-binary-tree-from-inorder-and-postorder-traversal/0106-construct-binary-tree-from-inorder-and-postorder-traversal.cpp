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
TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder,int inorderStart,int inorderEnd,int postorderStart,int postorderEnd,unordered_map<int,int>&indexes){
    if(inorderStart>inorderEnd || postorderStart>postorderEnd){
        return nullptr;
    }
    int rootVal=postorder[postorderEnd];
    TreeNode* root=new TreeNode(rootVal);
    int inorderRootIndex=indexes[rootVal];
    int leftTreeSize=inorderRootIndex-inorderStart;
    root->left=buildTreeHelper(inorder,postorder,inorderStart,inorderRootIndex-1,postorderStart,postorderStart+leftTreeSize-1,indexes);
    root->right=buildTreeHelper(inorder,postorder,inorderRootIndex+1,inorderEnd,postorderStart+leftTreeSize,postorderEnd-1,indexes);

    return root;
}

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> indexes;
        for(int i=0;i<inorder.size();i++){
            indexes[inorder[i]]=i;
        }
        return buildTreeHelper(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1,indexes);
    }
};