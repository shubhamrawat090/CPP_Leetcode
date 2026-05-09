class Solution {
private:
    vector<vector<int>> getFireTime(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        // Keep in mind to initialize with 1e9 so that in case fire doesn't reach the time is INFINITY so that player can reach here early
        vector<vector<int>> fireTime(rows, vector<int>(cols, 1e9));
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        queue<pair<int, int>> q;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    visited[i][j] = 1; // 1 is visited 
                    fireTime[i][j] = 0;
                } else if(grid[i][j] == 2) {
                    fireTime[i][j] = -1; // -1 is wall 
                }
            }
        }

        vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};

        int dist = 0;
        while(!q.empty()) {
            int size = q.size();
            dist++;
            while(size--) {
                auto top = q.front();
                q.pop();
                int i = top.first, j = top.second;
                for(auto& dir: dirs) {
                    int x = dir[0] + i, y = dir[1] + j;
                    if(x >= 0 && x < rows && y >= 0 && y < cols) { // Within bounds
                        if(grid[x][y] == 0 && !visited[x][y]) {
                            visited[x][y] = 1;
                            fireTime[x][y] = dist;
                            q.push({x, y});
                        }
                    }
                }
            }
        }

        return fireTime;
    }

    bool isPossible(vector<vector<int>>& fireTime, int currentTime) {
        int rows = fireTime.size(), cols = fireTime[0].size();
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = 1;
        vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()) {
            int size = q.size();
            currentTime++;
            while(size--) {
                auto top = q.front();
                q.pop();
                int i = top.first, j = top.second;
                for(auto& dir: dirs) {
                    int x = i + dir[0], y = j + dir[1];
                    if(x < 0 || y < 0 || x == rows || y == cols) continue; // out of bounds
                    if(visited[x][y]) continue; // visited already
                    if(fireTime[x][y] == -1) continue; // Wall 
                    if(x == rows-1 && y == cols-1 && currentTime <= fireTime[x][y]) return true;
                    if(currentTime < fireTime[x][y]) {
                        visited[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }
        }
        return false;
    }

public:
    int maximumMinutes(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> fireTime = getFireTime(grid);
        int low = 0, high = (rows * cols) + 1; // These are maximum and minimum times a person can wait
        // Question is Binary Search on answer; 
        // We try to wait for a particular time b/w low-high and then see if we can traverse the whose grid and reach end
        int ans = -1; // -1 means we cannot reach ever
        while(low <= high) {
            int mid = (low + high) / 2;
            if(isPossible(fireTime, mid)) {
                ans = mid; // go a possible answer
                low = mid + 1; // Try to wait for longer time
            } else {
                high = mid - 1; // Try to wait for lesser time
            }
        }

        // If I can wait for max amount of time then I can wait even more. Hence, a big value like 1e9 is returned
        return ans == (rows * cols) + 1 ? 1e9 : ans; 
    }
};