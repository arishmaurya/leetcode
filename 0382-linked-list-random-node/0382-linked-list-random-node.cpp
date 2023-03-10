
class Solution {
public:
    // Constructor that initializes the object with the head of the singly-linked list head.
    Solution(ListNode* head) {
        this->head = head;
        // Initialize the random number generator with the current time.
        srand(time(NULL));
    }
    
    // Chooses a node randomly from the list and returns its value.
    // All the nodes of the list should be equally likely to be chosen.
    int getRandom() {
        int result = head->val;   // Start with the value of the first node.
        ListNode* curr = head->next;
        int i = 2;
        while (curr != NULL) {
            // With probability 1/i, replace the previously selected value with the value of the current node.
            if (rand() % i == 0) {
                result = curr->val;
            }
            curr = curr->next;
            i++;
        }
        return result;
    }

private:
    ListNode* head;
};