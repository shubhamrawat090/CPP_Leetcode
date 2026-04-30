class Solution {
public:
    int rows, cols;
    vector<vector<vector<int>>> dp;

    int solve(vector<vector<int>>& grid, int i, int j, int cost) {
        if (i >= rows || j >= cols) return INT_MIN;

        int currCost = (grid[i][j] == 0 ? 0 : 1);
        int currScore = (grid[i][j] == 0 ? 0 : (grid[i][j] == 1 ? 1 : 2));

        if (cost < currCost) return INT_MIN;

        cost -= currCost;

        if (i == rows - 1 && j == cols - 1) {
            return currScore;
        }

        if (dp[i][j][cost] != -1) return dp[i][j][cost];

        int right = solve(grid, i, j + 1, cost);
        int down  = solve(grid, i + 1, j, cost);

        int bestNext = max(right, down);

        if (bestNext == INT_MIN)
            return dp[i][j][cost] = INT_MIN;

        return dp[i][j][cost] = currScore + bestNext;
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        rows = grid.size();
        cols = grid[0].size();

        dp = vector<vector<vector<int>>>(
            rows, vector<vector<int>>(cols, vector<int>(k + 1, -1))
        );

        int ans = solve(grid, 0, 0, k);
        return ans < 0 ? -1 : ans;
    }
};