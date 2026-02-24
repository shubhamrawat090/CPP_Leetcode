class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int left = grid[0][0], right = (n * n);
        while(left < right) {
            int mid = (left + right) / 2;

            vector<vector<bool>> vis(n, vector<bool>(n, false));
            if(isPossible(grid, 0, 0, vis, mid)) {
                right = mid;
            } else {
                left = mid+1;
            }
        }

        return left;
    }

    bool isPossible(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis, int T) {
        int n = grid.size();
        if(i < 0 || j < 0 || i >= n || j >= n) return false;
        if(vis[i][j] == true || grid[i][j] > T) return false;
        if(i == n-1 && j == n-1) return true;

        vis[i][j] = true;

        return isPossible(grid, i+1, j, vis, T) ||
        isPossible(grid, i-1, j, vis, T) ||
        isPossible(grid, i, j-1, vis, T) ||
        isPossible(grid, i, j+1, vis, T);
    }
};