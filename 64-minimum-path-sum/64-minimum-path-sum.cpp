class Solution {
public:
   int memoization(int i,int j,vector<vector<int>> &grid,vector<vector<int>>&dp){
       if(i==0&&j==0) return grid[0][0];        // base case 1
       if(i<0||j<0) return 1e9;                 // base case 2 here we cannot take INT_MAX because if we                                                       do that then recursive function will add grid[0][0]                                                       variable into int_max then it will be out of the                                                           integer range and we will get wrong answer
       if(dp[i][j]!=-1) return dp[i][j];
      int  up= grid[i][j]  + memoization(i-1,j,grid,dp);
      int left= grid[i][j]  +  memoization(i,j-1,grid,dp);
       return dp[i][j]=min(up,left);
        
   }
    int tabulation(int n,int m ,vector<vector<int>> &grid,vector<vector<int>>&dp){
         
        for(int i=0; i<n;i++){
            for(int j=0;j<m;j++){
               if(i==0&&j==0) dp[i][j]=grid[i][j];
                else{
                    int up=grid[i][j];
                    if(i>0) up+=dp[i-1][j];
                    else up+=1e9;
                    int left=grid[i][j];
                    if(j>0) left+=dp[i][j-1];
                    else left+=1e9;
                    
                    dp[i][j]=min(up,left);
                }
    
                
            }
        }
        return dp[n-1][m-1];
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return memoization(n-1,m-1,grid,dp);
        vector<vector<int>>dp(n,vector<int>(m,0));
        return tabulation(n,m,grid,dp);
    }
};