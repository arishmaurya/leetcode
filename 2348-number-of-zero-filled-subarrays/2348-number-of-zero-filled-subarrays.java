class Solution {
    public long zeroFilledSubarray(int[] nums) {

        long ans=0, curr=0;
        for(int i=0;i<nums.length; i++){
            curr=(nums[i]==0? curr +1 : 0);
            ans+=curr;
            
        }
        return ans;
    }
}
    
