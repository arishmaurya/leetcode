class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int ans=0, curr=0;
        for(auto num: nums){
            curr=(num==0? curr +1 : 0);
            ans+=curr;
            
        }
        return ans;
    }
};