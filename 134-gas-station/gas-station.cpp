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

        int availGas = 0, start = 0;
        for(int i=0; i<n; i++) {
            availGas += gas[i] - cost[i];
            if(availGas < 0) {
                start = i+1;
                availGas = 0;
            }
        }
        return start;
    }
};