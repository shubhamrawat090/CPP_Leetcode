class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Just check if total gas < total cost => YES => Trip never possible, return -1;
        int totalGas = 0, totalCost = 0;
        int n = gas.size();
        for(int i=0; i<n; i++) {
            totalGas += gas[i];
            totalCost += cost[i];
        }

        if(totalGas < totalCost) {
            return -1; // full circle trip never possible
        }

        int availGas = 0, start = 0;
        for(int i=0; i<n; i++) {
            availGas += gas[i] - cost[i];
            if(availGas < 0) {
                // if start --> i, the availGas is -ve then it will be for the points in between as well. So, startPt must be i+1
                start = i+1;
                availGas = 0; // reset gas because we start from here fresh
            }
        }
        return start;
    }
};