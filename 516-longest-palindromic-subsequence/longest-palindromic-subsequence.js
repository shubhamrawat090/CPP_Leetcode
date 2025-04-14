/**
 * @param {string} s
 * @return {number}
 */
var longestPalindromeSubseq = function(s) {
    const sRev = s.split("").reverse().join();
    return longestCommonSubsequence(s, sRev);
};

var longestCommonSubsequence = function (text1, text2) {
    return lcsSpaceOptimized(text1, text2);
};

function lcsSpaceOptimized(text1, text2) {
    const textLen1 = text1.length, textLen2 = text2.length;
    let prev = new Array(textLen2 + 1), curr = new Array(textLen2 + 1).fill(0);
    for (let j = 0; j <= textLen2; j++) {
        prev[j] = 0;
    }

    for (let i = 1; i <= textLen1; i++) {
        for (let j = 1; j <= textLen2; j++) {
            if (text1[i - 1] === text2[j - 1]) {
                // both match
                curr[j] = 1 + prev[j - 1];
            } else {
                // doesn't match
                curr[j] = Math.max(prev[j], curr[j - 1]);
            }
        }
        prev = [...curr]; ///// KEEP IN MIND TO DO LIKE THIS INSTEAD OF prev = curr
    }

    return prev[textLen2];
}