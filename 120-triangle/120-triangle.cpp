class Solution {
public:
    
int minimumPathSumUtil(int i, int j, vector<vector<int> > &triangle,int n, 
vector<vector<int> > &dp) {
  
  if(dp[i][j]!=-1)
  return dp[i][j];
  
  if(i==n-1) return triangle[i][j];
    
  int down = triangle[i][j]+minimumPathSumUtil(i+1,j,triangle,n,dp);
  int diagonal = triangle[i][j]+minimumPathSumUtil(i+1,j+1,triangle,n,dp);
  
  return dp[i][j] = min(down, diagonal);
  
}


    
int tabulation(vector<vector<int>>& triangle, int n){
    vector<vector<int> > dp(n,vector<int>(n,0));
    for(int j=0;j<n;j++){
        dp[n-1][j] = triangle[n-1][j];
    }
    for(int i=n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            
            int down = triangle[i][j]+dp[i+1][j];
            int diagonal = triangle[i][j]+dp[i+1][j+1];
            
            dp[i][j] = min(down, diagonal);
        }
    }
    
    return dp[0][0];
    }

    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
    //      vector<vector<int> > dp(n,vector<int>(n,-1));
    // return minimumPathSumUtil(0,0,triangle,n,dp);
        return tabulation(triangle,n);
    }
};