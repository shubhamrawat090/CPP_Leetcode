class Solution {
public:
    vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        fillMinDistances(grid, dist, n);

        int low = 0, high = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                high = max(high, dist[i][j]);
            }
        }

        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canReach(dist, mid, n)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }

    void fillMinDistances(vector<vector<int>>& grid,
                          vector<vector<int>>& dist,
                          int n) {

        queue<pair<int,int>> q;

        // Multi-source BFS
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (auto &dir : dirs) {
                int x = i + dir[0];
                int y = j + dir[1];

                if (x < 0 || y < 0 || x >= n || y >= n)
                    continue;

                if (dist[x][y] != INT_MAX)
                    continue;

                dist[x][y] = dist[i][j] + 1;
                q.push({x, y});
            }
        }
    }

    bool canReach(vector<vector<int>>& dist, int val, int n) {

        if (dist[0][0] < val)
            return false;

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        q.push({0,0});
        vis[0][0] = true;

        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            if (i == n - 1 && j == n - 1)
                return true;

            for (auto &dir : dirs) {
                int x = i + dir[0];
                int y = j + dir[1];

                if (x < 0 || y < 0 || x >= n || y >= n)
                    continue;

                if (vis[x][y])
                    continue;

                if (dist[x][y] < val)
                    continue;

                vis[x][y] = true;
                q.push({x, y});
            }
        }

        return false;
    }
};