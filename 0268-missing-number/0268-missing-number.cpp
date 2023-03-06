class Solution {
public:
    int missingNumber(vector<int>& nums) {
         int n= nums.size();
         int sum=(n*(n+1))/2;
         int mising=sum;
         for(int i=0;i<n;i++){
             mising-=nums[i];
         }
         return mising;
    }
};