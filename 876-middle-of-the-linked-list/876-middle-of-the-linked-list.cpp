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
    int getlength(ListNode* head){
        int i=0;
        while(head!=NULL){
            
            i++;
            head=head->next;
            
        }
        return i;
    }
    
    ListNode* middleNode(ListNode* head) {
        int len=getlength(head)/2;
        
        int cnt=0;
        ListNode* temp=head;
        while(cnt<len){
            temp=temp->next;
            cnt++;
        }
        return temp;
        
    }
};