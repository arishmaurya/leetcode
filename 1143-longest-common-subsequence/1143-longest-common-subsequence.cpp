class Solution {
    private:
    int memo(string s1,string s2, int ind1,int ind2,vector<vector<int>>&dp){
        if(ind1<0||ind2<0)return 0;
       if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        if(s1[ind1]==s2[ind2])return dp[ind1][ind2]=1+memo(s1,s2,ind1-1,ind2-1,dp);
        else{
            return dp[ind1][ind2]= max(memo(s1,s2,ind1-1,ind2,dp),memo(s1,s2,ind1,ind2-1,dp));
        }
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int ind1=text1.size();
        int ind2=text2.size();
      
        // vector<vector<int>>dp(ind1,vector<int>(ind2,-1));
            // return memo(text1,text2,ind1-1,ind2-1,dp);
        // memoization and recursion is not working so we have to use tabulation 
        
        //tabulation down here
        vector<vector<int>>dp(ind1+1,vector<int>(ind2+1,-1));
        // if(text1[0]==text2[0]) dp[0][0]=1;
        // else dp[0][0]=0;
        for(int i=0; i<=ind1; i++) dp[i][0]=0;
        for(int j=0; j<=ind2; j++) dp[0][j]=0;
        
        for(int i=1;i<=ind1; i++){
            for(int j=1;j<=ind2;j++){
                    if(text1[i-1]==text2[j-1]) dp[i][j]=1 +dp[i-1][j-1];
                    else{
                        dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
                    }
            }
        }
        return dp[ind1][ind2];
    }
};