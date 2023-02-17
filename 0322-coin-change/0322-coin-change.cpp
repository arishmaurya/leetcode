class Solution {
    private:
    int memo(vector<int>& coins, int amount,int ind,vector<vector<int>>&dp){
        if(ind==0){
                if(amount%coins[ind]==0)return amount/coins[ind];
                else{return 1e9;}
            }
         if(dp[ind][amount]!=-1)return dp[ind][amount];
        int nottake= 0 + memo(coins,amount,ind-1,dp);
        int take =INT_MAX;
        if(coins[ind]<=amount){
            take= 1+ memo(coins,amount-coins[ind],ind,dp);
        }
        return dp[ind][amount]=min(take,nottake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
//         int n= coins.size();
//         vector<vector<int>>dp(n,(vector<int>(amount+1,-1)));

//           int ans=memo(coins,amount,n-1,dp);
//         if(ans>=1e9)return -1;
//         return ans;
        
          int n= coins.size();
         vector<vector<int>>dp(n,(vector<int>(amount+1,-1)));
        
        for(int i=0; i<=amount; i++){
            if(i%coins[0]==0) dp[0][i]=i/coins[0];
            else dp[0][i] = 1e9;
        }
        
        for(int ind=1; ind<n; ind++){
            for(int target=0; target<=amount; target++){
                 
            int notTake = 0 + dp[ind-1][target];
            int take = 1e9;
            if(coins[ind]<=target)
                take = 1 + dp[ind][target - coins[ind]];
                
             dp[ind][target] = min(notTake, take);
            }
        }
        
         int ans=dp[n-1][amount];
          
        if(ans >=1e9) return -1;
        return ans;
    }
};