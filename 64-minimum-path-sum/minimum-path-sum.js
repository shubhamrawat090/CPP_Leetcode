/**
 * @param {number[][]} grid
 * @return {number}
 */
var minPathSum = function (grid) {
    // return minPathSumRecursion(grid, 0, 0);
    // const dp = Array.from({length: grid.length}, () => new Array(grid[0].length).fill(-1));
    // return minPathSumMemo(grid, 0, 0, dp);
    return minPathTabulate(grid, 0, 0);
};

var minPathTabulate = function (grid) {
    const rows = grid.length, cols = grid[0].length;
    const dp = Array.from({ length: rows }, () => new Array(cols).fill(0));

    // Base case: Bottom-right cell
    dp[rows - 1][cols - 1] = grid[rows - 1][cols - 1];

    // Fill the table from bottom-right to top-left
    for (let row = rows - 1; row >= 0; row--) {
        for (let col = cols - 1; col >= 0; col--) {
            if (row === rows - 1 && col === cols - 1) continue; // Skip last cell (already initialized)
            
            const down = row + 1 < rows ? dp[row + 1][col] : Infinity;
            const right = col + 1 < cols ? dp[row][col + 1] : Infinity;

            dp[row][col] = grid[row][col] + Math.min(down, right);
        }
    }

    return dp[0][0];
};

var minPathSumMemo = function (grid, row, col, dp) {
    const rows = grid.length, cols = grid[0].length;
    if (row >= rows || col >= cols) {
        return Number.MAX_VALUE;
    }

    if (dp[row][col] !== -1) {
        return dp[row][col];
    }

    if (row == rows - 1 && col == cols - 1) {
        return dp[row][col] = grid[row][col];
    }

    const down = minPathSumMemo(grid, row + 1, col, dp);
    const right = minPathSumMemo(grid, row, col + 1, dp);
    return dp[row][col] = grid[row][col] + Math.min(down, right);
}

var minPathSumRecursion = function (grid, row, col) {
    const rows = grid.length, cols = grid[0].length;
    if (row >= rows || col >= cols) {
        return Number.MAX_VALUE;
    }

    if (row == rows - 1 && col == cols - 1) {
        return grid[row][col];
    }

    const down = minPathSumRecursion(grid, row + 1, col);
    const right = minPathSumRecursion(grid, row, col + 1);
    return grid[row][col] + Math.min(down, right);
}