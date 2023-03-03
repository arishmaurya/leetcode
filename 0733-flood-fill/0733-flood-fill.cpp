class Solution {
    private:
    void dfs(vector<vector<int>>& image, int row, int col, int color,int inicolor,int delrow[],int delcol[],vector<vector<int>>&ans){
        ans[row][col]=color;
        int n=image.size();
        int m=image[0].size();
        for(int i=0; i<4; i++){
            int nrow=row + delrow[i];
            int ncol=col + delcol[i];
            if(nrow>=0&&nrow<n&& ncol>=0&& ncol<m&& image[nrow][ncol]==inicolor&& ans[nrow][ncol]!=color){
                dfs(image, nrow,ncol,color,inicolor,delrow,delcol,ans);
            }
        }
        
        
    }
    
    
    public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int inicolor=image[sr][sc];
    vector<vector<int>>ans=image;
    int delrow[]={-1,0,+1,0};
    int delcol[]={0,+1,0,-1};
        dfs(image, sr,sc, color,inicolor,delrow,delcol,ans);
        return ans;
    
    }
};