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
	bool isCompleteTree(TreeNode* root) {

		//if(!root->left and root->right) return false;
		queue<TreeNode*>q;
		q.push(root);
		vector<int>ans;
		ans.push_back(root->val);
		while(!q.empty()){

			for(int i=0;i<q.size();i++){

					TreeNode* temp=q.front();
					q.pop();
					if(temp->left){

							ans.push_back(temp->left->val);
							q.push(temp->left);
					}
					else{
							ans.push_back(-1);
					}
					if(temp->right){

							ans.push_back(temp->right->val);
							q.push(temp->right);
					}
					else{
							ans.push_back(-1);
					}

			}

		}

		for(int i=0;i<ans.size()-1;i++){

					if(ans[i]==-1 and ans[i+1]!=-1) return false;

		}


		return true;
	}
};