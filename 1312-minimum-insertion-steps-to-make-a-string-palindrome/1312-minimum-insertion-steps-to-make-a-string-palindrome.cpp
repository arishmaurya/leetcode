class Solution {
   private:
    int longestCommonSubsequence(string text1, string text2) {
        int ind1=text1.size();
        int ind2=text2.size();
 
        //tabulation down here
        vector<vector<int>>dp(ind1+1,vector<int>(ind2+1,0));

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
      int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        return longestCommonSubsequence(s,t);
        
    }
public:
    int minInsertions(string s) {
        return s.size()-longestPalindromeSubseq(s);
    }
};