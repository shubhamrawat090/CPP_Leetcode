class Solution {
    struct DSU {
        vector<int> parent;
        vector<int> rank;
        DSU(int n) {
            rank.resize(n, 0);
            parent.resize(n);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int find(int u) {
            if (parent[u] == u)
                return u;
            return parent[u] = find(parent[u]);
        }

        void unionByRank(int u, int v) {
            int pu = find(u);
            int pv = find(v);

            if (rank[pu] > rank[pv]) {
                parent[pv] = pu;
            } else if (rank[pu] < rank[pv]) {
                parent[pu] = pv;
            } else {
                parent[pu] = pv;
                rank[pv]++;
            }
        }
    };

public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0;
        for(auto& stone: stones) {
            int row = stone[0];
            int col = stone[1];
            maxRow = max(row, maxRow); 
            maxCol = max(col, maxCol); 
        }

        DSU dsu(maxRow + maxCol + 2);
        unordered_set<int> uniqueStones;
        for(auto& stone: stones) {
            // Each row is a node
            // Each col is a node
            // Example we have 4 rows and 4 cols.
            // Then nodes are: 0, 1, 2, 3 (FOR ROWS),    4, 5, 6, 7 (for COLS )
            int row = stone[0];
            int col = stone[1] + maxRow + 1;
            uniqueStones.insert(row);
            uniqueStones.insert(col);
            dsu.unionByRank(row, col);
        }

        int noOfComponents = 0;
        for(auto& node: uniqueStones) {
            if(dsu.find(node) == node) noOfComponents++;
        }

        // Following Components
        // C1: 1->2->3   C2: 4->5   C3->6
        // APPROACH: We can remove all node from a component, EXCEPT 1
        // Ans = n(C1)-1 + n(C2)-1 + n(C3)-1
        //     = [n(C1)+n(C2)+n(C3)] - [1+1+1]
        //     = n(total unique nodes) - n(no of. components)   
        int n = stones.size();
        return n - noOfComponents;
    }
};