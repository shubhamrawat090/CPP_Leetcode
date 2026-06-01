class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int n = cost.size();
        int totalCost = 0;
        for(int i=n-1; i>=0; i-=3) {
            int firstCandy = cost[i];
            int secondCandy = i == 0 ? 0 : cost[i-1];
            totalCost += firstCandy + secondCandy;
        }
        return totalCost;
    }
};