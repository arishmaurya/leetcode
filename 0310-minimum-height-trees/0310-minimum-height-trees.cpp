class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return {0};
        if(n==2)return {0,1};
        vector<int>inDegree(n+1,0);
        vector<int>adj[n];
        queue<int>q;
        for(auto it:edges){
            inDegree[it[1]]++;
            inDegree[it[0]]++;
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(inDegree[i]==1){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            int back=q.back();
            vector<int>v;
            do{
                node=q.front();
                v.push_back(node);
                q.pop();
                for(auto it:adj[node]){
                    inDegree[it]--;
                    if(inDegree[it]==1)q.push(it);
                }
            }while(node!=back);
            ans.push_back(v);
        }
        return ans.back();
    }
};