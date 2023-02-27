class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       vector<int>ans; 
        ans=nums1;
        for(int i=0; i<nums2.size(); i++){
            ans.push_back(nums2[i]);
        }
        sort(ans.begin(),ans.end());
        int n=ans.size();
        if(n%2!=0) return ans[n/2];
        else {
            double x=ans[n/2-1] ;
            double y=ans[n/2];
            double val=(x+y)/2;
              return val;
        }
        
    }
};