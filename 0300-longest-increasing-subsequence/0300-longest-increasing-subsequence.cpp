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
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return memo(nums,0,-1,n,dp);
    }
 
};