class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> p;
        for(auto it: stones) p.push(it);
        int y,x;
        while(p.size() > 1){
            y=p.top();
             p.pop();
            x=p.top();
             p.pop();
            
            if(x!=y) 
                p.push(y-x);
            
        }
        if(!p.empty()) return p.top();
        else return 0;
    }
};