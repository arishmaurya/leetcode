class Solution {
public:
   
    int rob1(vector<int>& nums) {
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
    
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp1;
        vector<int>temp2;
        if(n==1) return nums[0];
        for(int i=0; i<n; i++){
          if(i!=0)temp1.push_back(nums[i]);
          if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(rob1(temp1),rob1(temp2));
        
    }
};