class Solution {
    private:
       int memo(vector<int>&prices, int ind, int buy ,vector<vector<vector<int>>>&dp,int cap){
           if(cap==0)return 0;
            if(ind==prices.size())return 0;
           if(dp[ind][buy][cap]!=-1)return dp[ind][buy][cap];
           int profit=0;
           if(buy){
               profit=max(-prices[ind]+memo(prices,ind+1,0,dp,cap),0 + memo(prices,ind+1,1,dp,cap));
           }
           else{
                profit=max(prices[ind]+memo(prices,ind+1,1,dp,cap-1),0 + memo(prices,ind+1,0,dp,cap));
           }
           return dp[ind][buy][cap]=profit;
           
       } 
public:
    int maxProfit(int k, vector<int>& prices) {
       int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
      
       
        return memo(prices,0,1,dp,k);
    }
};