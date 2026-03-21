class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int rows = grid.size(), cols = grid[0].size();
        
        int rowStart = x, rowEnd = min(x + k - 1, rows - 1);
        int colStart = y, colEnd = min(y + k - 1, cols - 1);

        for(int j=colStart; j<=colEnd; j++) {
            int left = rowStart, right = rowEnd;
            while(left < right) {
                int temp = grid[left][j];
                grid[left][j] = grid[right][j];
                grid[right][j] = temp;
                left++;
                right--;
            }
        }

        return grid;
    }
};