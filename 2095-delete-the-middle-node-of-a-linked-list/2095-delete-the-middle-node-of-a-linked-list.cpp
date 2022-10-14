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
    ListNode* deleteMiddle(ListNode* head) {
        int n=0;
        ListNode* temp=head;
        while(temp!=nullptr) {
            n++;
            temp=temp->next;
            
        }
        n=n/2;
        temp=head;
      
         if(n==0){
            return NULL;
        }
        
         else {
             for(int i=1; i<=n;i++){
                 
             if(i==n){
                temp->next=temp->next->next;
                // head->next=nullptr;
                break;
            }
               temp=temp->next;
          }
         }
        return head;
       
    }
};