class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalGas = 0, totalCost = 0;
        for(int i=0; i<n; i++) {
            totalGas += gas[i];
            totalCost += cost[i];
        }

        if(totalGas < totalCost) return -1;

        int startStop = 0, tankFuel = 0;
        for(int i=0; i<n; i++) {
            tankFuel += gas[i] - cost[i];
            if(tankFuel < 0) {
                startStop = i + 1;
                tankFuel = 0;
            }
        }

        return startStop;
    }
};