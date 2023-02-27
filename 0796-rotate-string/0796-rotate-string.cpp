class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        

        int i = 0;
        int j = 0;
        int previ =-1;
        while(j<n && i<n){

            if(s[i]==goal[j]){
                if(previ ==-1){
                    previ=i;
                }
                i++;
                j++;
                if(i==n && j!=0){
                    i = 0;
                }
            }
            else{
                if(previ!=-1){
                    i = previ+1;
                    j = 0;
                    previ=-1;
                }
                else{
                    i++;
                }
            }
        }

        if(j==n){
            return true;
        }
        else{
            return false;
        }

    }
};