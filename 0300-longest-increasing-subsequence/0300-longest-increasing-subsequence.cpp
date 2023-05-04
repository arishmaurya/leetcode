class Solution {
    private: 
    int memo(vector<int>&nums,int ind,int prevInd,int size,vector<vector<int>>&dp){
        if(ind==size)return 0;
        if(dp[ind][prevInd+1]!=-1)return dp[ind][prevInd+1];
        int nottake= 0 + memo(nums,ind+1,prevInd,size,dp); //not take case 
        int take=0;
        if(prevInd==-1|| nums[ind]>nums[prevInd]) {
            take= 1+ memo(nums,ind+1,ind,size,dp);
        }  
        return dp[ind][prevInd +1]=max(take,nottake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return memo(nums,0,-1,n,dp);
        
        
          vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    
    for(int ind = n-1; ind>=0; ind --){
        for (int prev_index = ind-1; prev_index >=-1; prev_index --){
            
            int notTake = 0 + dp[ind+1][prev_index +1];
    
            int take = 0;
    
            if(prev_index == -1 || nums[ind] > nums[prev_index]){
                
                take = 1 + dp[ind+1][ind+1];
            }
    
            dp[ind][prev_index+1] = max(notTake,take);
            
        }
    }
    
    return dp[0][0];
    }
 
};