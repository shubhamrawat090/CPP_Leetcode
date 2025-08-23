/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function (board) {
    const rows = [], cols = [], boxes = [];
    const SIZE = 9;
    for (let i = 0; i < SIZE; i++) {
        rows.push(new Set());
        cols.push(new Set());
        boxes.push(new Set());
    }

    for (let i = 0; i < SIZE; i++) {
        for (let j = 0; j < SIZE; j++) {
            if (board[i][j] !== ".") {
                if (!isValid(board[i][j], i, j, rows, cols, boxes)) {
                    return false;
                } else {
                    rows[i].add(board[i][j]);
                    cols[j].add(board[i][j]);
                    boxes[(Math.floor(i / 3) * 3) + Math.floor(j / 3)].add(board[i][j]);
                }
            }
        }
    }

    return true;
};

function isValid(val, i, j, rows, cols, boxes) {
    return !rows[i].has(val) && !cols[j].has(val) && !boxes[(Math.floor(i / 3) * 3) + Math.floor(j / 3)].has(val);
}