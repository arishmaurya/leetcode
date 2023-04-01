class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        int ans;
        
        while(low<=high){
            int mid=low + (high-low)/2;
            if(target>nums[mid]){
                low=mid+1;
               
            }
            else if(target<nums[mid]){
                high=mid-1;
                
            }
            else if(target==nums[mid]){
                ans=mid;
                break;
            }
            else ans=-1;
        }
       return ans; 
    }
};