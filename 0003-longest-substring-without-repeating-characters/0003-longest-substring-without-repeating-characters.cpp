class Solution {
public:
    int lengthOfLongestSubstring(string s) {
  
        int n=s.length();
        unordered_map<char, int>mp;

        int ans=0;
        int left=0, right=0;

        while(right<n){
            char r=s[right];
            mp[r]++;
            while(mp[r]>1){
                char l=s[left];
                mp[l]--;
                left++;
            }

            ans=max(ans, right-left+1);
            right++;
        }

        return ans;
    

        
    }
};