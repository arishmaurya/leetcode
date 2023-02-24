class Solution {
// private: 
    // dp(vector<int>&arr,int n){
    //     if()
    // }
    
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size(); 
        // dp(prices,n);
        int mini=prices[0];
        int cost;
        int maxProfit=0;
        for(int i=1; i<n; i++){
            cost=prices[i]-mini;
            maxProfit=max(cost,maxProfit);
            mini=min(prices[i],mini);
        }
        return maxProfit;
        
    }
};