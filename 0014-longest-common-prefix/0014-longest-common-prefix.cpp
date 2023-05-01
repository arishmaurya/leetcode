class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res="";
        bool flag=true;
        for(int i=0; i<strs[0].size(); i++){
            char s=strs[0][i];
            for(int j=1; j<strs.size();j++){
                if(s!=strs[j][i]){
                    flag=false;
                    break;
                }
            }
            if(flag==false) break;
            else res+=s;
        }
        return res;
    }
};