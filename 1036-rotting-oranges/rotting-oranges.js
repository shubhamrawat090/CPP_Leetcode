/**
 * @param {number[][]} grid
 * @return {number}
 */
var orangesRotting = function(grid) {
    const queue = [];
    const m = grid.length, n = grid[0].length;
    let freshCount = 0;
    for(let i=0; i<m; i++) {
        for(let j=0; j<n; j++) {
            if(grid[i][j] === 2) {
                queue.push([i, j, 0]);
            } else if(grid[i][j] === 1) {
                freshCount++;
            }
        }
    }

    let maxTime = 0;
    const dirX = [-1, 0, 1, 0];
    const dirY = [0, 1, 0, -1];

    while(queue.length) {
        const [x, y, time] = queue.shift();
        for(let i=0; i<4; i++) {
            const newX = x + dirX[i];
            const newY = y + dirY[i];

            if(newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1) {
                grid[newX][newY] = 2;
                queue.push([newX, newY, time+1])
                maxTime = Math.max(maxTime, time+1);
                freshCount--;
            }
        }
    }

    return freshCount ? -1 : maxTime;
};