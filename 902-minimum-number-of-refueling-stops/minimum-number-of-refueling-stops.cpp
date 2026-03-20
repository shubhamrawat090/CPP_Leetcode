class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int maxReached = startFuel;
        int stationIndex = 0;
        priority_queue<int> pq;

        int countStops = 0;

        while(maxReached < target) {
            // while I can take the station
            // AND the station position is within maxReached
            // I collect it in maxHeap
            while(stationIndex < stations.size()
            && stations[stationIndex][0] <= maxReached
            ) {
                pq.push(stations[stationIndex][1]);
                stationIndex++; // move to next station
            }

            if(pq.empty()) return -1;

            maxReached += pq.top();
            pq.pop();

            countStops++;
        } 

        return countStops;
    }
};