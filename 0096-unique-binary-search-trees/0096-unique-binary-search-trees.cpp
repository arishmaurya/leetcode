class Solution {
private:
    int numTree(int n, vector<long long>&dp,long long ans){
       if(n<=1){
            return 1;
        }
        if(dp[n]!=-1)return dp[n];
        for(int i=1;i<=n; i++){
            ans+=numTree(i-1,dp,ans)*numTree(n-i,dp,ans);
        }
        return dp[n]=ans;
    }
public:
    int numTrees(int n) {
        vector<long long>dp(n+1,-1);
          long long ans=0;
        
         numTree(n,dp,ans);
        if(n<=1)return 1;
        return dp[n];
    }
};