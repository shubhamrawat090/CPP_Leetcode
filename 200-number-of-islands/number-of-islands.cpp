class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int count = 0;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j] != '0') { // a new island starts
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
        int rows = grid.size(), cols = grid[0].size();
        if(i < 0 || i >= rows || j < 0 || j >= cols) return;

        // mark curr visited
        grid[i][j] = '0';

        // i-1, j
        // i, j+1
        // i+1, j
        // i, j-1
        vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for(int k=0; k<4; k++) {
            int newRow = i + dir[k].first;
            int newCol = j + dir[k].second;
            if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                if(grid[newRow][newCol] == '1') {
                    dfs(grid, newRow, newCol);
                }
            }
        }
    }
};