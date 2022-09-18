class Solution {
public:
    int f( int i, int j, vector<vector<int>>& grid,vector<vector<int>>&dp){
        
     if(i==0&&j==0) return 1;
     if(i<0 || j<0 || grid[i][j]==1) return 0;
      if(dp[i][j]!=-1)return dp[i][j];
      int up=0; int down=0;
       up=f(i-1,j,grid,dp);
       down=f(i,j-1,grid,dp);
     
        return dp[i][j]=up+down;
    }
//     int tabulation(int n, int m, vector<vector<int>>&grid,vector<vector<int>>&dp){
//         for(int i=0; i<n;i++){
//             for(int j=0; j<m;j++){
//                 if(i>0 && j>0 && grid[i][j]==1){
//                 dp[i][j]=0;
//                 continue;
//                 }
//             if(i==0&&j==0) {
//                 dp[i][j]=1;
//                   continue;
//                 }
//                int up=0;
//                 int left=0;
//                 if(i>0) up=dp[i-1][j];
//                 if(j>0) left=dp[i][j-1];
//                 dp[i][j]=up+left;
            
            
            
//         }
//     }
//         return dp[n][m];
//     }     
    int tabulation(int n, int m, vector<vector<int>>&grid,vector<vector<int>>&dp){
        dp[0][0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if( i > 0 )
                    dp[i][j] += dp[i - 1][j];
                if( j > 0 )
                    dp[i][j] += dp[i][j - 1];
                if( grid[i][j] == 1 )
                    dp[i][j] = 0;
            }
        }
        return dp[n - 1][m - 1];
    } 
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
                                   
     int n = obstacleGrid.size();
     int m = obstacleGrid[0].size(); 
       vector<vector<int>>dp(n,vector<int>(m,0));
       // return f(n-1,m-1,obstacleGrid,dp);
        return tabulation(n,m,obstacleGrid,dp);
        
        
        
    }
};