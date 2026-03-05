class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int count = 0;

        int maxReached = startFuel;
        // maxheap to store fuel offered by stations i.e. stations[i][1]
        // Just to make sure that most fuel offerring stations is available at top
        priority_queue<int> pq;

        int index = 0; 

        while(maxReached < target) { // I proceed till I haven't reached the target
            // I collect all fuel offered by stations(Within my reach) in the Priority Queue
            while(
                index < stations.size() // until I can store stations' fuel 
                && stations[index][0] <= maxReached // within my reach
            ) {
                pq.push(stations[index][1]); 
                index++;
            }

            // if I don't have any fuel available by stations then I stop, I cannot go beyond my maxReach
            if(pq.empty()) return -1;

            // I have fuel's available, I take the one with most fuel and my maxReach increases
            maxReached += pq.top();
            pq.pop(); // remove from stored fuels

            count++;

        }

        return count;
    }
};