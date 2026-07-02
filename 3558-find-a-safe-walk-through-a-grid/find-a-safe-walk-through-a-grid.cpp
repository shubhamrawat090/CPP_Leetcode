class Solution {
    typedef vector<int> T;
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        // Dijkstra - Find minimum health(shortest path sum) to reach n-1, m-1
        // At the end health - result[n-1][m-1] >= 1
        int rows = grid.size(), cols = grid[0].size();
        priority_queue<T, vector<T>, greater<T>> pq;
        vector<vector<int>> result(rows, vector<int>(cols, INT_MAX));
        pq.push({grid[0][0], 0, 0});
        result[0][0] = grid[0][0];

        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            
            int dist = top[0];
            int i = top[1];
            int j = top[2];

            if (dist > result[i][j]) continue;

            for(auto& dir: dirs) {
                int x = i + dir[0];
                int y = j + dir[1];
                if(x < 0 || y < 0 || x >= rows || y >= cols) continue;
                if(result[x][y] > result[i][j] + grid[x][y]) {
                    result[x][y] = result[i][j] + grid[x][y];
                    pq.push({result[x][y], x, y});
                }
            }
        }

        return health - result[rows-1][cols-1] >= 1;
    }
};