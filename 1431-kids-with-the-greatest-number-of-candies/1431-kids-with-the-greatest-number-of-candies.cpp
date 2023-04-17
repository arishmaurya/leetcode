class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int size = candies.size();
        int min = 0;
        vector<bool>result;
   
        min = *max_element(candies.begin(), candies.end());
        for(int i=0;i<size;i++)
        {
            if((candies[i]+extraCandies)>=min)
            {
               result.push_back(true);
            }
            else
            {
               result.push_back(false);
            }
        }
        return result;
        
    }
};