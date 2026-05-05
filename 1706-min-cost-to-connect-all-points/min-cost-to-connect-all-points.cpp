class Solution {
    struct DSU {
        vector<int> parent;
        vector<int> rank;
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for(int i=0; i<n; i++) {
                parent[i] = i;
            }
        }

        int find(int u) {
            if(parent[u] == u) return parent[u]; // or return u;
            return parent[u] = find(parent[u]); // path compression here
        }

        void unionByRank(int u, int v) {
            int pu = find(u), pv = find(v);
            if(rank[pu] > rank[pv]) {
                parent[pv] = pu;
            } else if(rank[pv] > rank[pu]) {
                parent[pu] = pv;
            } else {
                // Same rank --> INCREASE
                parent[pv] = pu;
                rank[pu]++;
            }
        }
    };

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges;

        int n = points.size();
        for(int u=0; u<n; u++) {
            int ux = points[u][0], uy = points[u][1];
            for(int v=0; v<n; v++) {
                int vx = points[v][0], vy = points[v][1];
                if(u == v) continue; // No edge for same point

                int cost = abs(ux - vx) + abs(uy - vy);

                edges.push_back({cost, u, v});
            }
        }

        sort(edges.begin(), edges.end());

        DSU dsu(n);

        int sum = 0;
        for(vector<int>& edge: edges) {
            int u = edge[1], v = edge[2], w = edge[0];

            if(dsu.find(u) != dsu.find(v)) {
                // Different component can be part of MST
                sum += w;
                dsu.unionByRank(u, v);
            }
        }
        return sum;
    }
};