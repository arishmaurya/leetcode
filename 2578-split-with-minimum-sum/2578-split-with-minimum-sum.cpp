class Solution {
public:
    int splitNum(int num) {
        string s=to_string(num);
       
        int num1;
        int num2;
        
        int sum=0;
        int n=s.size();
        sort(s.begin(),s.end());
         string str2=""; 
        string str1=""; 
        for(int i=0; i<n; i+=2) str1+=s[i];
        for(int i=1; i<n; i+=2) str2+=s[i];

   
        num1=stoi(str1); 
        num2=stoi(str2);
        sum=num1+ num2;
        return sum;
    }
};