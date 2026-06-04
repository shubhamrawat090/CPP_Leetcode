class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<int> curr(cols, 0);
        vector<int> prev(cols, 0);
        prev[0] = grid[0][0];
        for(int j=1; j<cols; j++) {
            prev[j] = prev[j-1] + grid[0][j];
        }
        for(int i=1; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                int left = j == 0 ? INT_MAX : curr[j-1];
                int top = prev[j];
                curr[j] = min(left, top) + grid[i][j];
            }
            prev = curr;
        }
        return prev[cols-1];
    }
};