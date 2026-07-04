class Solution {
    struct DSU {
        vector<int> parent;
        vector<int> rank;
        DSU(int n) {
            parent.resize(n);
            for(int i=0; i<n; i++) {
                parent[i] = i;
            }
            rank.resize(n+1, 0);
        }

        int find(int u) {
            if(parent[u] == u) return parent[u];
            return parent[u] = find(parent[u]);
        }

        void unionByRank(int u, int v) {
            int pu = find(u), pv = find(v);

            if(rank[pu] < rank[pv]) {
                parent[pu] = pv;
            } else if(rank[pv] > rank[pu]) {
                parent[pv] = pu;
            } else {
                // same rank
                parent[pu] = pv;
                rank[pv]++;
            }
        }
    };
public:
    int minScore(int n, vector<vector<int>>& roads) {
        /*
            IDEA:
            Inside the 1 component where node 1 is we need the LEAST COST
        */
        // return useDFS(n, roads);
        return useDSU(n, roads);
    }

    int useDSU(int n, vector<vector<int>>& roads) {
        DSU dsu(n+1);

        // Group them
        for(auto& edge: roads) {
            int u = edge[0], v = edge[1];
            dsu.unionByRank(u, v);
        }

        // Ultimate parent of node 1
        int ultParent = dsu.find(1);

        // Find minimum cost of whoever is in same group(HAS SAME ultParent)
        int ans = INT_MAX;
        for(auto& edge: roads) {
            int u = edge[0], v = edge[1], cost = edge[2];
            if(dsu.find(v) == ultParent) ans = min(ans, cost);
        }    
        return ans;
    }

    int useDFS(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& edge : roads) {
            int u = edge[0], v = edge[1], c = edge[2];
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }

        int ans = INT_MAX;
        vector<int> visited(n + 1, 0);
        dfs(1, adj, visited, ans);
        return ans;
    }

    void dfs(int node, vector<vector<pair<int, int>>>& adj,
             vector<int>& visited, int& ans) {
        visited[node] = 1;

        for (auto& nbr : adj[node]) {
            int nbrNode = nbr.first, nbrCost = nbr.second;
            ans = min(ans, nbrCost);
            if (!visited[nbrNode]) {
                dfs(nbrNode, adj, visited, ans);
            }
        }
    }
};