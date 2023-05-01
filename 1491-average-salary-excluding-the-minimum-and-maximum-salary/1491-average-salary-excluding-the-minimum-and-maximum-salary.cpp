class Solution {
public:
    double average(vector<int>& salary) {
      double  mini=1e6;
      double maxi=1000;
        double sum=0;
        double cnt=0;
        for(int i=0; i<salary.size();i++){
            double x=salary[i];
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
