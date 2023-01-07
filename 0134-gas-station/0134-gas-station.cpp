class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int collect = 0;
        int x = 0;
        int y = 0;
        for (int i = 0; i < gas.size(); i++) {
            collect += gas[i];
            collect -= cost[i];
            x += gas[i];
            y += cost[i];
            if (collect < 0) {
                start = i + 1;
                collect = 0;
            }
        }
        return x < y ? -1 : start;
    }
};