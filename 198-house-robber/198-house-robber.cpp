class Solution {
public:
    int rob(vector<int>& nums) {
        // this is tabulation way 
    // int n=nums.size();
    // vector<int>dp(n,0);
    // dp[0]=nums[0];
    // int negative=0;
    // int i=1;
    // for(int i=1; i<n;i++){
    //     int take=nums[i];
    //    if(i>1){
    //        take+=dp[i-2];
    //    }
    //    int notTake= 0 + dp[i-1];
    //    dp[i]=max(take,notTake);
    //  } 
    //     return dp[n-1];
        
        // space optimization after tabulation
         int n=nums.size();
    
     int prev=nums[0];
    int prev2=0;
    int i=1;
    for(int i=1; i<n;i++){
      int take=nums[i];
      if(i>1){
           take+=prev2;
       }
       int notTake= 0 + prev;
      int curr=max(take ,notTake);
       prev2=prev;
       prev=curr;
   } 
    return prev;
        
        
    }
};