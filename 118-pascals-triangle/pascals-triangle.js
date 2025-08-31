/**
 * @param {number} numRows
 * @return {number[][]}
 */
var generate = function(numRows) {
    let ans = [];
    for(let i=0; i<numRows; i++) {
        const rowArr = new Array(i+1).fill(0);
        rowArr[0] = 1;
        rowArr[rowArr.length - 1] = 1;
        ans.push(rowArr);
    }

    for(let i=2; i<numRows; i++) {
        const rowLen = ans[i].length;
        for(let j=1; j<rowLen-1; j++) {
            ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
        }
    }

    return ans;
};