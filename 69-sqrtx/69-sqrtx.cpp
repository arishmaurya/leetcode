class Solution {
public:
    int mySqrt(int x) {
        if(x==1) return 1;
    int low =0 ,high=x/2,ans=0;
        while(low<=high){
            long long mid=low+(high-low)/2;
            if(mid*mid<=x) {
                ans=mid;
                low=mid+1;
                
            }
            else high=mid-1;
            
            
        }
        return ans;
        
    }
};