//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int knapsackUtil(int W, int wt[], int val[], int ind, vector<vector<int>>& dp){

    if(ind == 0){
        if(wt[0] <=W) return val[0];
        else return 0;
    }
    
    if(dp[ind][W]!=-1)
        return dp[ind][W];
        
    int notTaken = 0 + knapsackUtil(W, wt, val, ind-1, dp);
    
    int taken = INT_MIN;
    if(wt[ind] <= W)
        taken = val[ind] + knapsackUtil(W-wt[ind],wt,val,ind-1,dp);
        
    return dp[ind][W] = max(notTaken,taken);
}
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       
     vector<vector<int>> dp(n,vector<int>(W+1,-1));
     return knapsackUtil(W, wt, val, n-1, dp);

       
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends