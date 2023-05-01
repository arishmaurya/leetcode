class Solution {
public:
    double average(vector<int>& salary) {
      float mini=1e6;
      float maxi=1000;
        double sum=0;
        double cnt=0;
        for(int i=0; i<salary.size();i++){
            float x=salary[i];
            mini=min(mini,x);
            maxi=max(maxi,x);
        }
       for(int i=0; i<salary.size();i++){
           if(salary[i]==mini|| salary[i]==maxi)continue;
           else{
               sum+=salary[i];
               cnt++;
           }
       }
        return sum/cnt;
    }
};
