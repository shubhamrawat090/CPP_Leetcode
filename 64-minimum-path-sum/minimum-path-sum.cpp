class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<int> prev(cols);
        int sum = 0;
        for(int j=0; j<cols; j++) {
            sum += grid[0][j];
            prev[j] = sum;
        }

        for(int i=1; i<rows; i++) {
            vector<int> curr(cols);
            curr[0] = grid[i][0] + prev[0];
            for(int j=1; j<cols; j++) {
                curr[j] = grid[i][j] + min(curr[j-1], prev[j]);
            }
            prev = curr;
        }

        return prev[cols-1];
    }
};