/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function (matrix) {
    transpose(matrix, matrix.length);
    reverseRows(matrix, matrix.length);
};

function transpose(matrix, n) {
    // Idea (In-place transpose) - ONLY POSSIBLE IN PLACE FOR SQUARE MATRIX
    // - Loop through the upper triangle of the matrix (above the diagonal).
    // - Swap matrix[i][j] with matrix[j][i].
    // - This way, you don’t overwrite values twice.

    // I will loop through lower triangle it is easier
    for (let i = 0; i < n; i++) {
        for (let j = 0; j < i; j++) {
            swapMatrix(matrix, i, j, j, i);
        }
    }
}

function reverseRows(matrix, n) {
    for (let row = 0; row < n; row++) {
        let left = 0, right = n - 1;
        while (left < right) {
            swapMatrix(matrix, row, left, row, right);
            left++;
            right--;
        }
    }
}

function swapMatrix(matrix, ar, ac, br, bc) {
    matrix[ar][ac] = matrix[ar][ac] ^ matrix[br][bc];
    matrix[br][bc] = matrix[ar][ac] ^ matrix[br][bc];
    matrix[ar][ac] = matrix[ar][ac] ^ matrix[br][bc];
}