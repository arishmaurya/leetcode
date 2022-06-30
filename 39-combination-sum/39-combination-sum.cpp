class Solution {
public:
    void findcombination(int indx,vector<int>& candidates, vector<vector<int>>&ans,vector<int>&ds,int target )
    {
      if(indx==candidates.size()){
          if(target==0) ans.push_back(ds);
          return;
              
      }  
        if(candidates[indx]<=target){
            ds.push_back(candidates[indx]);
            findcombination(indx,candidates,ans,ds,target-candidates[indx]);
            ds.pop_back();
        }
        findcombination(indx+1,candidates,ans,ds,target);
           
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        findcombination(0,candidates, ans,ds, target);
        return ans;
        
    }
};