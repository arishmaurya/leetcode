class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()==1)return 0;
        if(nums[0]>nums[1])return 0;
        if(nums[n-1]>nums[n-2])return n-1;
        int start=1; 
        int end=nums.size()-2;
        while(start<=end){
            int mid=start+ (end-start)/2;
            if(nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1])return mid;
            else if(nums[mid-1]>nums[mid]) end=mid-1;
            else start=mid+1;
        }
        return -1;
    }
};