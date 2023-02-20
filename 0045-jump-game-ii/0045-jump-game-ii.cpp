class Solution {
public:
     int solve(vector<int>& nums, vector<int>& dp, int i, int n){
        if(i == n-1)
            return dp[i] = 0;

        if(dp[i] != -1)
            return dp[i];
            
        int mini = 1e9;
        for(int j = 1; j <= nums[i]; j++){
            if(i+j < n){
                int count = 1 + solve(nums, dp, i+j, n);
                mini = min(mini, count);
            }
            
        }
        
        return dp[i] = mini;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums, dp, 0, n);
    }

};