class Solution {
    typedef pair<int, int> P;

private:
    vector<vector<vector<int>>> createAdj(vector<vector<int>>& times, int n) {
        vector<vector<vector<int>>> adj(n + 1);
        for(vector<int>& time: times) {
            int u = time[0], v = time[1], w = time[2];
            adj[u].push_back({v, w});
        }
        return adj;
    }

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Create Dijkstra Array of source -> all nodes
        // Among time of individual nodes take the max value -> in that time all nodes will get the signal
        // If any node is INF means that cannot reach from source --> return -1; // IMPOSSIBLE CASE
        
        vector<vector<vector<int>>> adj = createAdj(times, n);
        
        vector<int> dist(n + 1, INT_MAX);
        // Priority queue -> dist, node --> MINHEAP
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, k});
        dist[k] = 0; // k is src

        while(!pq.empty()) {
            P top = pq.top();
            pq.pop();
            int d = top.first;
            int u = top.second;

            if(d > dist[u]) continue; // no need to process a node where a SMALLER distance has been found

            // Relax neighbors
            for(vector<int> nbr: adj[u]) {
                int v = nbr[0], w = nbr[1];

                if(dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                } 
            }
        }

        int maxTime = 0;
        for(int i=1; i<=n; i++) {
            int d = dist[i];
            if(d == INT_MAX) return -1; // impossible case
            maxTime = max(maxTime, d);
        }

        return maxTime;
    }
};