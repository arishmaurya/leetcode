class Solution {
public:
    int romanToInt(string s) {
        long ans=0;
        int i=0;
        int n=s.length();
        while(i<s.length()){
            if(s[i]=='M'){
                ans+=1000;
                i++;
            }
            else if(s[i]=='D'){
                ans+=500;
                i++;
            }
            else if(s[i]=='C'){
                if(s[i+1]=='D' && i!=n-1){
                    ans+=400;
                    i++;
                }
                else if(s[i+1]=='M' && i!=n-1){
                    ans+=900;
                    i++;
                }
                else{
                    ans+=100;
                }
                i++;
            }
            else if(s[i]=='L'){
                ans+=50;
                i++;
            }
            else if(s[i]=='X'){
                if(s[i+1]=='L' && i!=n-1){
                    ans+=40;
                    i++;
                }
                else if(s[i+1]=='C' && i!=n-1){
                    ans+=90;
                    i++;
                }
                else{
                    ans+=10;
                }
                i++;
            }
            else if(s[i]=='V'){
                ans+=5;
                i++;
            }
            else if(s[i]=='I'){
                if(s[i+1]=='V' && i!=n-1){
                    ans+=4;
                    i++;
                }
                else if(s[i+1]=='X' && i!=n-1){
                    ans+=9;
                    i++;
                }
                else{
                    ans+=1;
                }
                i++;
            }
        }
        return ans;
    }
};