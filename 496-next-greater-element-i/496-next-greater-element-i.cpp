class Solution {
public:
    
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      
    unordered_map<int,int>m;
        for(int i=0; i<nums2.size(); i++)
        {
            m[nums2[i]]=i;
        }
         vector<int>v;
        for(int i=0;i<nums1.size(); i++)
        {  
            int k=m[nums1[i]];
            int indx=-1;
            
            for(int j=k+1; j<nums2.size(); j++){
                if(nums1[i]<nums2[j]){
                 indx=nums2[j];
                    break;
                   
                }
                                 
            }
            v.push_back(indx);

        }
        return v;
        
        
    }
};




