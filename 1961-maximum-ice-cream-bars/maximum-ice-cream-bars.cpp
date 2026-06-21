class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int freq[100001] = {0};
        for(int cost: costs) {
            freq[cost]++;
        }

        int count = 0;
        for(int i=0; i<100001; i++) {
            while(freq[i] > 0 && i <= coins) {
                coins -= i;
                freq[i]--;
                count++;
            }

            if(coins == 0) break;
        }

        return count;
    }
};