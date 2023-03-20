
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
            int prev = NULL;
			int next = NULL;
			int counter = 0;
	
			for (int i = 0; i < flowerbed.size() ; i++)
			{
				if (i == flowerbed.size()-1)
					next = NULL;
				else
					next = flowerbed[i + 1];
				if (flowerbed[i] == 0 && (prev == 0 || prev == NULL) && (next == 0 || next == NULL))
				{
					counter++;
					prev = 1;
				}
				else
					prev = flowerbed[i];
		
			}
			if (n <= counter)
				return true;
			return false;
        
    }
};