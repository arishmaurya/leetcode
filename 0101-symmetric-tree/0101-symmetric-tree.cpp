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
    bool symmetrical(TreeNode* p, TreeNode* q){
    if(p==NULL&&q==NULL) return true;
     else if(p==NULL||q==NULL) return false;
        else if(p->val!=q->val) return false;
        return symmetrical(p->left,q->right)&&symmetrical(p->right,q->left);
        
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return symmetrical(root->left,root->right);
        
//         bool flag=false;
//         if(!root) return false;
//         queue<TreeNode*>q;
//         q.push(root);
//         while(!q.empty()){
//             int n= q.size();
//             vector<int>level;
//             for(int i=0;i<n; i++){
//                 TreeNode*node=q.front();
//                 q.pop();
//                 if(node->left!=nullptr)q.push(node->left);
//                 if(node->right!=nullptr)q.push(node->right);
//                 level.push_back(node->val);
                
//             }
            
//             int size=level.size();
//             for(int j=0;j<size; j++){
//                 if(size%2==0&&level[size-1-j]==level[size+j]) {
//                     flag=true;
//                 }
                
//             }
            
          
//         }
//         return flag;
    }
};