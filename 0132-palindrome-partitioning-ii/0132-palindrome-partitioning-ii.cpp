class Solution {
private:
    int fun(int ind, string &s, int n, vector<int>&dp){
        if(ind==n)return 0;
        if(dp[ind]!=-1)return dp[ind];
        int minCost=INT_MAX;
        for(int j=ind; j<n; j++){
            if(isPalindrome(s,ind,j)){
                int cost= 1+fun(j+1, s, n,dp);
                minCost=min(minCost,cost);
            }
        }
        return dp[ind]= minCost;
        }
    bool isPalindrome(string &s, int start, int end){
        while(start<end){
            if(s[start]!=s[end])return false;
             start++;
                end--;
           }
            
        
        return true;
    }
public:
    int minCut(string s) {
      
        int n=s.size();
          vector<int>dp(n+1,0);
        // fun(0,s,n,dp);
        //tabulation
        dp[n]=0;
        for(int i=n-1; i>=0; i--){
            
            int minCost=INT_MAX;
        for(int j=i; j<n; j++){
            if(isPalindrome(s,i,j)){
                int cost= 1+ dp[j+1];
                minCost=min(minCost,cost);
            }
        }
        dp[i]= minCost;
        }
        
        return dp[0]-1;
    }
};