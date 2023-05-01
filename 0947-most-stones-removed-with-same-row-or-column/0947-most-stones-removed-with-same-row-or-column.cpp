class DisjointSet{
	vector<int>rank,parent;

public:
	DisjointSet(int n){
		rank.resize(n+1,0);
		parent.resize(n+1,0);
		for(int i=0; i<=n; i++){
			parent[i]=i;
		}
	}
	int findUPar(int node){
		if(node==parent[node])return node;
		return parent[node]=findUPar(parent[node]);
	}
	// u and v are to different node values 
	void unionByRank(int u, int v){
		int ulp_u=findUPar(u);
		int ulp_v=findUPar(v);
		if(ulp_u==ulp_v)return;
		if(rank[ulp_u]<rank[ulp_v]){
			parent[ulp_u]=ulp_v;
		}
		else if(rank[ulp_v]<rank[ulp_u]){
			parent[ulp_v]=ulp_u;
		}
		else{
			parent[ulp_v]=ulp_u;
			rank[ulp_u]++;
		}
	}
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxRow=0;
        int maxCol=0;
        for(auto it: stones){
            maxRow=max(maxRow,it[0]);
            maxCol=max(maxCol,it[1]);
        }
        DisjointSet ds(maxRow + maxCol +1);
        unordered_map<int,int>stoneNode;
        for(auto it: stones){
            int nodeRow=it[0];
            int nodeCol=it[1] + maxRow +1;
            ds.unionByRank(nodeRow,nodeCol);
            stoneNode[nodeRow]=1;
            stoneNode[nodeCol]=1;
            
        }
        int cnt=0;
        for(auto it: stoneNode){
            if(ds.findUPar(it.first)==it.first) cnt++;
        }
        return n- cnt;
        
    }
};