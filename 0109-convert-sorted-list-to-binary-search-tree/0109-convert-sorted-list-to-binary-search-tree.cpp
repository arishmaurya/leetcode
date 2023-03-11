/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode *solve(ListNode *head,  ListNode *end){
    
    if(head == end)
        return nullptr;
    
    ListNode *slow = head, *fast = head;
    while(fast != end and fast->next != end){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    TreeNode *temp = new TreeNode(slow->val);
    temp->left = solve(head, slow);
    temp->right = solve(slow->next, end);
    
    return temp;
}
public:
   TreeNode* sortedListToBST(ListNode* head) {
      return solve(head, nullptr);
}
};