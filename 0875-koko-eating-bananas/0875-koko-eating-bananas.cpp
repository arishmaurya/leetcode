class Solution {
public:
    bool is_possibleToFinish(vector<int>piles,int h,int k)
    {

        int hours=0;
        int i=0;
        while((hours<=h)&&(i<piles.size()))
        {
            hours+=(int)ceil((double)piles[i]/k);
            i++;

        }
        return (hours<=h);
    }

    int minEatingSpeed(vector<int>& piles, int h) {
            sort(piles.begin(), piles.end());
            int lo =1;
            int hi = piles[piles.size()-1];
            int mid = 1;
            if (h==piles.size())
            return hi;
            while (lo <hi)
            {
 mid=(hi+lo)/2;
if (is_possibleToFinish(piles,h,mid))
            hi = mid;
        else
            lo = mid + 1;

            }

            return (is_possibleToFinish(piles,h,mid)) ? mid :mid+1;
    }
};