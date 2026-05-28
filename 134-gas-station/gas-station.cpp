class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        int n = gas.size();
        for(int i=0; i<n; i++) {
            totalGas += gas[i];
            totalCost += cost[i];
        }

        if(totalGas < totalCost) return -1;
        
        int ans = 0;
        int netCost = 0;
        for(int i=0; i<n; i++) {
            netCost += (gas[i]-cost[i]);
            if(netCost < 0) {
                netCost = 0;
                ans = i+1;
            }
        }

        return ans;
    }
};