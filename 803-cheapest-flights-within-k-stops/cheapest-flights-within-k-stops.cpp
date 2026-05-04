class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        /* STORE IN-TERMS OF STOPS RATHER THAN DISTANCE IN QUEUE - Priority QUEUE NOT NEEDED BECAUSE STOPS INCREASE BY +1 as opposed to cost/distances */
        vector<vector<pair<int, int>>> adj(n);
        for(auto flight: flights) {
            int u = flight[0], v = flight[1], w = flight[2];
            adj[u].push_back({v, w});
        }

        queue<pair<int, pair<int, int>>> q;
        vector<int> dist(n, 1e9);

        dist[src] = 0;
        // {stops, {node, cost}}
        q.push({0, {src, 0}});

        while(!q.empty()) {
            auto top = q.front();
            q.pop();
            int stops = top.first;
            int node = top.second.first;
            int cost = top.second.second;

            if(stops > k) continue; // cannot proceed as no. of max allowed stops is increased

            for(auto nbr: adj[node]) {
                int nbrNode = nbr.first;
                int nbrCost = nbr.second;

                if(cost + nbrCost < dist[nbrNode]) {
                    if(stops <= k) { // We are allowing till K stops before neighbor because neighbor can be destination as well
                        dist[nbrNode] = cost + nbrCost;
                        q.push({stops+1, {nbrNode, dist[nbrNode]}});
                    }
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};