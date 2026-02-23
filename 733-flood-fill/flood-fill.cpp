class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int r = image.size(), c = image[0].size();
        dfs(image, sr, sc, image[sr][sc], color, r, c);
        return image;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int oldVal, int newVal, int r, int c) {
        if(i < 0 || j < 0 || i >= r || j >= c || grid[i][j] != oldVal || grid[i][j] == newVal) {
            return;
        }

        grid[i][j] = newVal;

        dfs(grid, i+1, j, oldVal, newVal, r, c);
        dfs(grid, i-1, j, oldVal, newVal, r, c);
        dfs(grid, i, j+1, oldVal, newVal, r, c);
        dfs(grid, i, j-1, oldVal, newVal, r, c);
    }
};