class Solution {
public:
    bool checkIfPangram(string sentence) {
        int n=sentence.length();
        bool ans=true;
        map<int,int>mp;
        for(int i=0; i<n; i++){
            mp[sentence[i]]++;
            
        }
        if(mp.size()<26) ans=false;
        for(auto it: mp){
            if(it.second<1){
                ans=false;
                break;
            }
        }
        return ans;
    }
};