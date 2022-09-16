class Solution {
public:
    int f( int i, int j, vector<vector<int>>& grid,vector<vector<int>>&dp){
        
     if(i==0&&j==0&&!grid[i][j]) return 1;
     
     // if(i>0&&j>0 && grid[i][j]==1)return 0;
     // if(i<0||j<0) return 0;
         if(i<0 || j<0 || grid[i][j]==1) return 0;
      
      
     if(dp[i][j]!=-1)return dp[i][j];
      int up=0; int down=0;
       up=f(i-1,j,grid,dp);
       down=f(i,j-1,grid,dp);
     
        return dp[i][j]=up+down;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
                                   
     int n = obstacleGrid.size();
     int m = obstacleGrid[0].size(); 
       vector<vector<int>>dp(n,vector<int>(m,-1));
       return f(n-1,m-1,obstacleGrid,dp);
        
        
        
    }
};