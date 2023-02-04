class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        stack<int>st;
        for(int i=0; i<nums.size();i++){
            int value=nums[i];
          if(value<10)ans.push_back(value);
            
            else {
                while(value>0){
                int temp=value%10;
               st.push(temp);
                    value/=10;
            }
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
        }
            }
        
        return ans;
    }
};