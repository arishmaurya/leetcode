class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int size=arr.size()-1;
        int i;
        int j=0;
        int count=0;
        for(i=1;i<10000;i++){
            if(j==arr.size()){
                count++;
            }
            else if(arr[j]!=i){
                count++;
            }
            else{
                j++;
            }

            if(count==k){
                break;
            }
        }
        return i;
    }
};