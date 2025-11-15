class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        bool ans = false;
        helper(grid, visited, rows, cols, ans, 0, 0, 0);
        return ans;
    }

    void helper(vector<vector<int>>& grid, vector<vector<bool>>& visited,
                int rows, int cols, bool& ans, int i, int j, int val) {
        if (i < 0 || j < 0 || i >= rows || j >= cols) {
            return;
        }

        if (val == (rows * cols) - 1) {
            ans = true;
            return;
        }

        visited[i][j] = true;

        vector<vector<int>> dirs = {{-2, -1}, {-2, 1}, {-1, 2}, {1, 2},
                                    {2, 1},   {2, -1}, {1, -2}, {-1, -2}};

        for (vector<int> dir : dirs) {
            int x = i + dir[0], y = j + dir[1];
            if (x >= 0 && y >= 0 && x < rows && y < cols && grid[x][y] == val+1 && !visited[x][y]) {
                helper(grid, visited, rows, cols, ans, x, y, val + 1);
            }
        }

        visited[i][j] = false;
    }
};