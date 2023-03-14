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
    int fullSum = 0;

    void dfs(TreeNode* node, int currSum) {
        if (node == NULL)
            return;

        currSum = currSum*10 + node->val;

        if (node->left==NULL && node->right==NULL) {
            fullSum += currSum;
            currSum = 0;
        }

        dfs(node->left, currSum);
        dfs(node->right, currSum);
    }

    int sumNumbers(TreeNode* root) {
        dfs(root, 0);

        return fullSum;
    }
};