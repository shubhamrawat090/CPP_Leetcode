class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // pq is maxHeap. decreasing order of station[1] => fuel
        priority_queue<int> pq;
        int fueled = 0, start = 0, dist = startFuel;
        int n = stations.size();
        while(dist < target) {
            while(start < n && dist >= stations[start][0]) {
                // we can take this station
                pq.push(stations[start][1]);
                start++;
            }
            if(pq.empty()) {
                // could not go upto any of the next stations
                return -1;
            }

            int maxFuelStation = pq.top();
            pq.pop();
            dist += maxFuelStation;
            fueled++;
        }
        return fueled;
    }
};