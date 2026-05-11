class Solution {
    int recursive(int r1, int c1, int r2, vector<vector<int>>& grid) {
        int n = grid.size();
        int c2 = r1 + c1 - r2;
        if (r1 < 0 || r1 >= n || r2 < 0 || r2 >= n || c1 >= n || c2 >= n)
            return -1e9; // Some very small value
        if (grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return -1e9; // Blocked way
        int cherries = 0;
        if (r1 == r2 && c1 == c2) {
            cherries =
                grid[r1][c1]; // If both on same cell then only 1 will take
        } else {
            cherries = grid[r1][c1] + grid[r2][c2];
        }

        // Allowed moves: right(i, j+1), down: (i+1, j)
        vector<vector<int>> dirs = {{0, 1}, {1, 0}};
        // If robot1 moves down, robot2 can move down, right.
        // If robot1 moves right, robot2 can move down, right.
        // So, total 4 combinations

        int maxValue = INT_MIN;
        for (int d1 = 0; d1 < 2; d1++) {
            int nr1 = r1 + dirs[d1][0], nc1 = c1 + dirs[d1][1];
            for (int d2 = 0; d2 < 2; d2++) {
                int nr2 = r2 + dirs[d2][0], nc2 = c2 + dirs[d2][1];
                int value = recursive(nr1, nc1, nr2, grid);
                maxValue = max(value, maxValue);
            }
        }
        return maxValue;
    }

    int memoized(int r1, int c1, int r2, vector<vector<int>>& grid,
                 vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int c2 = r1 + c1 - r2;
        if (r1 < 0 || r1 >= n || r2 < 0 || r2 >= n || c1 >= n || c2 >= n)
            return -1e9; // Some very small value
        if (r1 == n - 1 && c1 == n - 1 && r2 == n - 1 && c2 == n - 1) {
            // Both robot reached end
            return grid[n - 1][n - 1]; // count once
        }

        if (grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return -1e9; // Blocked way

        if (dp[r1][c1][r2] != -1)
            return dp[r1][c1][r2]; // Return precomputed answer

        int cherries = 0;
        if (r1 == r2 && c1 == c2) {
            cherries =
                grid[r1][c1]; // If both on same cell then only 1 will take
        } else {
            cherries = grid[r1][c1] + grid[r2][c2];
        }

        // Allowed moves: right(i, j+1), down: (i+1, j)
        vector<vector<int>> dirs = {{0, 1}, {1, 0}};
        // If robot1 moves down, robot2 can move down, right.
        // If robot1 moves right, robot2 can move down, right.
        // So, total 4 combinations

        int maxValue = INT_MIN;
        for (int d1 = 0; d1 < 2; d1++) {
            int nr1 = r1 + dirs[d1][0], nc1 = c1 + dirs[d1][1];
            for (int d2 = 0; d2 < 2; d2++) {
                int nr2 = r2 + dirs[d2][0], nc2 = c2 + dirs[d2][1];
                int remainValue = memoized(nr1, nc1, nr2, grid, dp);
                int value = cherries + remainValue;
                maxValue = max(value, maxValue);
            }
        }
        return dp[r1][c1][r2] = maxValue;
    }

    int tabulate(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(n, vector<int>(n, 0)));
        for (int r1 = n - 1; r1 >= 0; r1--) {
            for (int c1 = n - 1; c1 >= 0; c1--) {
                for (int r2 = n - 1; r2 >= 0; r2--) {
                    int c2 = r1 + c1 - r2;
                    // c2 can be negative for r1=0, c1=0, r2=2
                    if(c2 < 0 || c2 >= n) continue; // Do not process for -ve indexes

                    if (r1 == n - 1 && c1 == n - 1 && r2 == n - 1 &&
                        c2 == n - 1) {
                        // Both robot reached end
                        dp[r1][c1][r2] = grid[n - 1][n - 1]; // count once
                        continue;
                    }

                    if (grid[r1][c1] == -1 || grid[r2][c2] == -1) {
                        dp[r1][c1][r2] = -1e9; // Blocked way
                        continue;
                    }

                    int cherries = 0;
                    if (r1 == r2 && c1 == c2) {
                        cherries = grid[r1][c1]; // If both on same cell then
                                                 // only 1 will take
                    } else {
                        cherries = grid[r1][c1] + grid[r2][c2];
                    }

                    // Allowed moves: right(i, j+1), down: (i+1, j)
                    vector<vector<int>> dirs = {{0, 1}, {1, 0}};
                    // If robot1 moves down, robot2 can move down, right.
                    // If robot1 moves right, robot2 can move down, right.
                    // So, total 4 combinations

                    int maxValue = INT_MIN;
                    for (int d1 = 0; d1 < 2; d1++) {
                        int nr1 = r1 + dirs[d1][0], nc1 = c1 + dirs[d1][1];
                        for (int d2 = 0; d2 < 2; d2++) {
                            int nr2 = r2 + dirs[d2][0], nc2 = c2 + dirs[d2][1];
                            int remainValue = -1e9;
                            if(
                                nr1 >= 0 && nr1 < n &&
                                nr2 >= 0 && nr2 < n &&
                                nc1 >= 0 && nc1 < n &&
                                nc2 >= 0 && nc2 < n
                            ) {
                                remainValue = dp[nr1][nc1][nr2];
                            }
                            int value = cherries + remainValue;
                            maxValue = max(value, maxValue);
                        }
                    }
                    dp[r1][c1][r2] = maxValue;
                }
            }
        }

        return dp[0][0][0];
    };

public:
    int cherryPickup(vector<vector<int>>& grid) {
        // Think of the question like 2 robots at (0, 0) want to go to (n-1,
        // n-1) simulatneously. Then how would you solve this? Moves of a robot
        // from (0,0) ==> (r1, c1) = r1 + c1 ==> BECAUSE going right -> j+1,
        // going down -> i+1 At any pt of time: MOVES_OF_ROBOT1 ==
        // MOVES_OF_ROBOT2 r1 + c1 == r2 + c2 r1 + c1 - r2 = c2; // 3D DP
        // instead of 4D int ans = recursive(0, 0, 0, grid);

        // int n = grid.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(n,
        // vector<int>(n, -1))); int ans = memoized(0, 0, 0, grid, dp);

        int ans = tabulate(grid);
        return max(0, ans);
    }
};