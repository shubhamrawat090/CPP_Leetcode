/**
 * @param {number} numRows
 * @return {number[][]}
 */
var generate = function(numRows) {
    if (numRows === 0) return [];

    const triangle = [[1]]; // Start with the first row

    for (let i = 1; i < numRows; i++) {
        const prevRow = triangle[i - 1];
        const newRow = [1]; // Start the new row with a 1

        for (let j = 1; j < i; j++) {
            // Calculate middle elements from the previous row
            newRow.push(prevRow[j - 1] + prevRow[j]);
        }

        newRow.push(1); // End the new row with a 1
        triangle.push(newRow);
    }

    return triangle;
};
