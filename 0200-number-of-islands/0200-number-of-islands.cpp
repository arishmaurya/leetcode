class Solution {
    private:
    void dfs(vector<vector<char>>&grid,vector<vector<int>>&ans,int row,int col, int delrow[],int delcol[],int n,int m){
        ans[row][col]=1;
        for(int i=0; i<4; i++){
            int nrow= row + delrow[i];
            int ncol= col + delcol[i];
            if(nrow>=0&&nrow<n&&ncol>=0&& ncol<m &&ans[nrow][ncol]!=1&&grid[nrow][ncol]=='1'){
                 dfs(grid,ans,nrow,ncol,delrow,delcol,n,m);
            }
        }
        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
     int delrow[]= {-1,0,1,0};
     int delcol[]={0,+1,0,-1};
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>ans(n,vector<int>(m,0));
        for(int i=0; i<n;i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1'&&ans[i][j]!=1){
                    dfs(grid,ans,i,j,delrow,delcol,n,m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};