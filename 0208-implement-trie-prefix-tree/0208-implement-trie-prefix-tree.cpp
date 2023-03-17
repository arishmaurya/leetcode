class TNode{
    public : 
        bool isLeaf;
        TNode* nextLetter[26];

        TNode(){
            for(int i = 0;i<26;i++)
                nextLetter[i] = NULL;

            isLeaf = false;    
        }       
};


class Trie {
public:
    TNode* root;
    Trie() {
         root = new TNode();
    }
    
    void insert(string word) {
        TNode* head = root;
        
        for(int i = 0; i<word.length()-1;i++){
            int pos = word[i] - 'a';
            
            if(!head->nextLetter[pos]) 
                head->nextLetter[pos] = new TNode();    
            
            head = head->nextLetter[pos];
        }
        
        int last = word[word.length()-1] - 'a';
        if(!head->nextLetter[last]) 
            head->nextLetter[last] = new TNode();
        
        head = head->nextLetter[last];
        head->isLeaf = true;
    }
    
    bool search(string word) {
        TNode* head = root;
        
        for(int i = 0; i<word.length()-1;i++){
            int pos = word[i] - 'a';
            if(head->nextLetter[pos]) 
                head = head->nextLetter[pos];
            
            else return false;
        }
        
        int last = word[word.length()-1] - 'a';
        if(head->nextLetter[last] && head->nextLetter[last]->isLeaf)  
            return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TNode* head = root;
        
        for(int i = 0; i<prefix.length();i++){
            int pos = prefix[i] - 'a';
            if(head->nextLetter[pos]) 
                head = head->nextLetter[pos];
            else return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */