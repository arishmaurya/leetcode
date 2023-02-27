class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack==needle){
            return 0;
        }
        if(haystack.length()==needle.length() && haystack!=needle){
            return -1;
        }
        char a=needle[0];
        int s=needle.length();
        for(int i=0;i+s<=haystack.length();i++){
            if(haystack[i]==a){
                string b=haystack.substr(i,s);
                if(b==needle){
                    return i;
                }
            }
        }
        return -1;
    }
};