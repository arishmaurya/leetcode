// class Solution {
// private:
//     int dfs(row,col,vector<vector<int>>& grid,int cnt){
//         int n=grid.size();
//         int m=grid[0].size();
        
//         if(row>n&&col>m)return;
//         if(row<=n&&col<=m){
//             cnt
//         }
        
//     }
// public:
//     int maxMoves(vector<vector<int>>& grid) {
//         int ans;
//         int cnt=0;
//         for(int i=0; i<grid.size();i++){
//            ans= dfs(i,0,grid,cnt);
//         }
//         return ans;
        
//     }
// };
class Solution {
public:

    int helper(vector<vector<int>>& grid,int i,int j,int prev,int row,int col,vector<vector<int>>&dp){

        if(i<0 || j<0 || i>=row || j>=col || grid[i][j]<=prev){
           return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        dp[i][j] = max(helper(grid,i-1,j+1,grid[i][j],row,col,dp),
                        max(helper(grid,i,j+1,grid[i][j],row,col,dp),
                                    helper(grid,i+1,j+1,grid[i][j],row,col,dp)))+1;
        return dp[i][j];
        
    }
    int maxMoves(vector<vector<int>>& grid) {
        int ma=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<grid.size();i++){
            helper(grid,i,0,0,grid.size(),grid[0].size(),dp);
        }
        // For calculating ans;
        for(int i=0;i<n;i++){
            ma=max(ma,dp[i][0]);
        }
        return ma-1;
    
    }
};