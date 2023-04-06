class Solution {
    private:
   void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<int>>& grid,int delrow[],int delcol[]){


        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;

        
        for(int i=0; i<4; i++){
           int nrow=row + delrow[i];
           int ncol=col + delcol[i];
        
        if(nrow<n&&nrow>=0&&ncol<m&&ncol>=0&&!vis[nrow][ncol]&&grid[nrow][ncol]==0){
            dfs(nrow,ncol,vis,grid,delrow,delcol);
        }  
        }
   
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
     int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        vector<vector<int>>vis(n,vector<int>(m,0));
        // marking boundary and excluding boundry elements 
        for(int j=0;j<m;j++){
       if(!vis[0][j] && grid[0][j]==0){
           dfs(0,j,vis,grid,delrow,delcol);
       }
       if(!vis[n-1][j] && grid[n-1][j]==0){
           dfs(n-1,j,vis,grid,delrow,delcol);
       }
   }
    for(int i=0;i<n;i++){
        if(!vis[i][0] && grid[i][0]==0){
            dfs(i,0,vis,grid,delrow,delcol);
        }
        if(!vis[i][m-1] && grid[i][m-1]==0){
            dfs(i,m-1,vis,grid,delrow,delcol);
        }
    }
        // now dfs for inner islands and we will count how many times we did dfs that will be our ans
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==0&&grid[i][j]==0){
                   dfs(i,j,vis,grid,delrow,delcol); 
                    cnt++;
                }   
            }
        }
        return cnt;
    }
};