class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = INT_MIN, minSoFar = INT_MAX;

        for(int price: prices) {
            if(price > minSoFar) {
                profit = max(profit, price - minSoFar);
            }
            minSoFar = min(minSoFar, price);
        }

        return profit == INT_MIN ? 0 : profit;
    }
};