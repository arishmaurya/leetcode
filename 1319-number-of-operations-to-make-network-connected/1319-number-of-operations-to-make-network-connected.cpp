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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }
        DisjointSet ds(n);
        int numberofConnectedComponents=n;
        for(auto & connection:connections){
            if(ds.findUPar(connection[0])!=ds.findUPar(connection[1])){
                numberofConnectedComponents--;
                ds.unionByRank(connection[0],connection[1]);
            }
        }
        return numberofConnectedComponents-1;
    }
};