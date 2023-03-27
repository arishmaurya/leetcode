// class Solution {
//     public:
//     int dfs(vector<vector<int>>&matrix, int row, int col,vector<vector<int>>&vis){
//           int nrow,ncol;
//        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        
//         if(vis[row][col]!=-1)return vis[row][col];
//         int ans=0;
//            for(int i=0; i<4; i++){
//            int nrow = row+dir[i].first;
//            int ncol = col+dir[i].second;
            
//          if(matrix[nrow][ncol]<=matrix[row][col])return 0;
//         if(row<0||row>=matrix.size()||col<0||col>=matrix[0].size())return 0;
//              ans=max(ans,dfs(matrix,nrow,ncol,vis)); 
               
//           }
//      return vis[row][col]=ans+1;
//     }
// public:
//     int longestIncreasingPath(vector<vector<int>>& matrix) {
//       int result=0;
//         int n=matrix.size();
//         int m=matrix[0].size();
//         vector<vector<int>>vis(n+1,vector<int>(m+1,-1));
//         for(int i=0; i<n-1; i++){
//             for(int j=0; j<m-1; j++){
//             result=max(result,dfs(matrix,i,j,vis));
//             }
//         }
       
//         return result;
//     }
// };




class Solution {
public:
  
  
    int dfs(vector<vector<int>> &matrix,int i,int j,vector<vector<int>> &dp){
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
 
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
   
        int maxx=0;
        for(int k=0;k<4;k++){
  
           int x = i+dir[k].first;
           int y = j+dir[k].second;

           if(x<0 || x>=matrix.size() || y>=matrix[0].size() || y<0){
               continue;
           }
           if(matrix[x][y]<=matrix[i][j]){
               continue;
           }
             maxx=max(maxx,dfs(matrix,x,y,dp));   //also put in else condition:
        

        }
        return dp[i][j]=maxx+1;

    }
   

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int res=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                res =  max(res,dfs(matrix,i,j,dp));
            }
        }
        return res;
    }
};
