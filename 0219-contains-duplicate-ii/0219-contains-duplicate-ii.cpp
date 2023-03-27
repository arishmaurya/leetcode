class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
//         bool ans=false;
//         bool temp=true;
        
//         for(int i=0;i<nums.size();i++){
//             int j=i+1;
//             while(temp){
//                 if(abs(i-j)<=k){
//                   nums[i]==nums[j]? ans=true: j++;
//                 }
//                 else{
//                     temp=false;
//                 }
//             }
            
            
//         }
//         return ans;
        unordered_map<int,int>mp;
        for(int i=0; i<nums.size(); i++){
            if(mp.find(nums[i])!=mp.end()){
                if(abs(i-mp[nums[i]]<=k))return true;
            }
           mp[nums[i]]=i;
        }
        return false;
    }
};