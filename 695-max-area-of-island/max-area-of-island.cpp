class Solution {
private:
    int dfs(vector<vector<int>>& grid, int i, int j, int& rows, int& cols) {
        int area = 0;
        grid[i][j] = -1;

        vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0},  {0, 1}};

        for (auto& dir : dirs) {
            int x = i + dir[0], y = j + dir[1];

            if (x >= 0 && x < rows && y >= 0 && y < cols) {
                if (grid[x][y] == 1) {
                    area += dfs(grid, x, y, rows, cols);
                }
            }
        }

        return 1 + area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int maxArea = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(grid, i, j, rows, cols));
                }
            }
        }
        return maxArea;
    }
};