class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minTillNow = prices[0];
        int maxProfit = 0;
        for(int i=1; i<prices.size(); i++) {
            // try to sell
            int sellPrice = prices[i] - minTillNow;
            maxProfit = max(sellPrice, maxProfit);
            minTillNow = min(minTillNow, prices[i]);
        }
        return maxProfit;
    }
};