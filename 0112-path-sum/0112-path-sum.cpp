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
   int tS;
bool check(TreeNode *node, int Sum)
{

    if (not node)
        return false;
    if (not node->left and not node->right and (node->val + Sum == tS))
        return true;

    int ans = 0;
    if (node->right)
        ans = ans or check(node->right, Sum + node->val);
    if (ans)
        return ans;
    if (node->left)
        ans = ans or check(node->left, node->val + Sum);
    return ans;
}
bool hasPathSum(TreeNode *root, int targetSum)
{tS=targetSum;
int Sum=0;
return check(root, Sum);
    
}
};