class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, int> te;
        while(head!=NULL){
            te[head]++;
            if(te[head]>1){
                return head;
                break;
            }
            head=head->next;
        } 
        return NULL;   
    }
};