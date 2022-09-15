class Solution {
public:
//    int countWaysUtil(int i, int j, vector<vector<int> > &dp) {
//   if(i==0 && j == 0)
//     return 1;
//   if(i<0 || j<0)
//     return 0;
//   if(dp[i][j]!=-1) return dp[i][j];
    
//   int up = countWaysUtil(i-1,j,dp);
//   int left = countWaysUtil(i,j-1,dp);
  
//   return dp[i][j] = up+left;
  
// }
    
    int uniquePaths(int m, int n) {
        // tabulation
        
    //     vector<vector<int> > dp(m,vector<int>(n,-1));
    // // return countWaysUtil(m-1,n-1,dp);
    //     for(int i=0; i<m; i++){
    //         for(int j=0; j<n; j++){
    //         if(i==0&&j==0) {
    //             dp[i][j]=1;
    //         continue;
    //         }
    //          int down=0;
    //             int right=0;
    //             if(i>0) down = dp[i-1][j];
    //             if(j>0) right= dp[i][j-1];
    //             dp[i][j]=down + right;
    //         }
    //     }
    //     return dp[m-1][n-1];
        
        
        // space optimaization
         vector<int> prev(n,0);
    for(int i=0; i<m; i++){
        vector<int> temp(n,0);
        for(int j=0; j<n; j++){
            if(i==0 && j==0){
                temp[j]=1;
                continue;
            }
            
            int up=0;
            int left =0;
            
            if(i>0)
                up = prev[j];
            if(j>0)
                left = temp[j-1];
                
            temp[j] = up + left;
        }
        prev = temp;
    }
    
    return prev[n-1];
        
    }
};