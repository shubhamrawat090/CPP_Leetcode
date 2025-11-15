class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        
        // Knight tour must start at 0,0 with value 0
        if (grid[0][0] != 0) return false;

        bool ans = false;
        helper(grid, rows, cols, ans, 0, 0, 0);
        return ans;
    }

    void helper(vector<vector<int>>& grid,
                int rows, int cols, bool& ans, int i, int j, int val) {
        
        if (val == rows * cols - 1) {
            ans = true;
            return;
        }

        vector<vector<int>> dirs = {
            {-2, -1}, {-2, 1}, {-1, 2}, {1, 2},
            {2, 1}, {2, -1}, {1, -2}, {-1, -2}
        };

        for (auto &dir : dirs) {
            int x = i + dir[0], y = j + dir[1];

            if (x >= 0 && y >= 0 && x < rows && y < cols &&
                grid[x][y] == val + 1) {

                helper(grid, rows, cols, ans, x, y, val + 1);
                return;  // IMPORTANT: stop after correct next move
            }
        }
    }
};
