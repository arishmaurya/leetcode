class Node{
    public:
    string data;
    Node* next;
    Node* prev;
    Node(string a){
        data = a;
        next = prev = NULL;
    }
};
class BrowserHistory {
public:
    Node* curr;
    BrowserHistory(string homepage) {
        curr = new Node(homepage);
    }
    
    void visit(string url) {
        curr->next = new Node(url);
        curr->next->prev = curr;
        curr = curr->next;
    }
    
    string back(int steps) {
        while(curr->prev!=NULL && steps>0){
            steps--;
            curr = curr->prev;
        }

        return curr->data;
    }
    
    string forward(int steps) {
        while(curr->next!=NULL && steps>0){
            steps--;
            curr = curr->next;
        }

        return curr->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */