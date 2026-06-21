class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int freq[100001] = {0};
        for(int cost: costs) {
            freq[cost]++;
        }

        int count = 0;
        for(int i=0; i<100001; i++) {
            if(freq[i] > 0 && i <= coins) {
                // How many bars of this cost can we buy?
                int canBuy = min(freq[i], coins / i);
                count += canBuy;
                coins -= canBuy * i;
                
                // If we can't buy any more, break early
                if (canBuy == 0) break;
            }

            if(coins == 0) break;
        }

        return count;
    }
};