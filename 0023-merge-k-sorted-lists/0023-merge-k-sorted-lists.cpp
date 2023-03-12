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
class Solution {
public:
    vector<int> tem;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(auto x:lists){
            ListNode* temp_Node = x;
            while(temp_Node!=NULL){
                tem.push_back(temp_Node->val);
                temp_Node = temp_Node->next;
            }
        }
        sort(tem.begin(),tem.end());
        reverse(tem.begin(),tem.end());
        ListNode *head = NULL;
        for(auto x:tem){
            ListNode *p = new ListNode(x);
            p->next = head;
            head = p;
        }
        return head;
    }
};