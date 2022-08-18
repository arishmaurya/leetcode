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
    int sumvalue(TreeNode* root,int &sum){
        if(root==nullptr) return 0;
        int lv=max(0,sumvalue(root->left,sum));
        int rv=max(0,sumvalue(root->right,sum));
        sum=max(sum,lv+rv+root->val);
        return max(lv,rv)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        sumvalue(root,sum);
        return sum;
        
        
    }
};