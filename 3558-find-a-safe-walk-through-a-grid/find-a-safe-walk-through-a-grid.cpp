class Solution {
    typedef vector<int> T;
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        // return dijkstra(grid, health);
        return zero_one_BFS(grid, health);
    }
    
    bool zero_one_BFS(vector<vector<int>>& grid, int health) {
        // 0-1 BFS - Find minimum health(shortest path sum) to reach n-1, m-1
        // 0 -> push_front(), 1 -> push_back(), ALWAYS pop_front()
        // At the end health - result[n-1][m-1] >= 1
        int rows = grid.size(), cols = grid[0].size();
        deque<T> dq;
        vector<vector<int>> result(rows, vector<int>(cols, INT_MAX));
        dq.push_front({grid[0][0], 0, 0});
        result[0][0] = grid[0][0];

        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};

        while(!dq.empty()) {
            auto top = dq.front();
            dq.pop_front();

            int dist = top[0];
            int i = top[1];
            int j = top[2];

            if(dist > result[i][j]) continue;

            for(auto& dir: dirs) {
                int x = i + dir[0];
                int y = j + dir[1];

                if(x < 0 || y < 0 || x >= rows || y >= cols) continue;

                if(result[x][y] > result[i][j] + grid[x][y]) {
                    result[x][y] = result[i][j] + grid[x][y];
                    if(grid[x][y] == 0) {
                        dq.push_front({result[x][y], x, y});
                    } else {
                        dq.push_back({result[x][y], x, y});
                    }
                }
            }
        }

        return health - result[rows-1][cols-1] >= 1;
    }

    bool dijkstra(vector<vector<int>>& grid, int health) {
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