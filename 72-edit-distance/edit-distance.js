/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var minDistance = function (word1, word2) {
    // return minDistanceRecursion(word1, word2, word1.length - 1, word2.length - 1);
    // const dp = Array.from({length: word1.length}, () => Array(word2.length).fill(-1))
    // return minDistanceMemo(word1, word2, word1.length - 1, word2.length - 1, dp);
    return minDistanceTabulation(word1, word2);
};

var minDistanceTabulation = function (word1, word2) {
    const len1 = word1.length, len2 = word2.length;
    // We can't access -1 in array. SO WE SHIFT INDEXING TO 1 RIGHT => dp[i][j] : word1[i-1][j-1]
    const dp = Array.from({ length: len1 + 1 }, () => Array(len2).fill(0));

    for (let i = 0; i <= len1; i++) {
        // Word2 empty => DELETE i chars from WORD1 to match WORD2
        dp[i][0] = i;
    }

    for (let j = 0; j <= len2; j++) {
        // Word1 empty => INSERT j chars in WORD1 to match WORD2
        dp[0][j] = j;
    }

    for (let i = 1; i <= len1; i++) {
        for (let j = 1; j <= len2; j++) {
            // Same 
            if (word1[i-1] === word2[j-1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                // Replace 
                const replaceChar = 1 + dp[i - 1][j - 1];
                // Insert
                const insertChar = 1 + dp[i][j - 1];
                // Delete
                const deleteChar = 1 + dp[i - 1][j];
                dp[i][j] = Math.min(replaceChar, insertChar, deleteChar);
            }
        }
    }
    return dp[len1][len2];
}

var minDistanceMemo = function (word1, word2, i, j, dp) {
    if (j < 0) {
        return i + 1; // i + 1 deletions left from string 1
    } else if (i < 0) {
        return j + 1; // j + 1 insertions left in string 1
    }

    if (dp[i][j] !== -1) {
        return dp[i][j];
    }

    // Same 
    if (word1[i] === word2[j]) {
        return dp[i][j] = minDistanceMemo(word1, word2, i - 1, j - 1, dp);
    } else {
        // Replace 
        const replaceChar = 1 + minDistanceMemo(word1, word2, i - 1, j - 1, dp);
        // Insert
        const insertChar = 1 + minDistanceMemo(word1, word2, i, j - 1, dp);
        // Delete
        const deleteChar = 1 + minDistanceMemo(word1, word2, i - 1, j, dp);
        return dp[i][j] = Math.min(replaceChar, Math.min(insertChar, deleteChar));
    }
}
var minDistanceRecursion = function (word1, word2, i, j) {
    if (j < 0) {
        return i + 1; // i + 1 deletions left from string 1
    } else if (i < 0) {
        return j + 1; // j + 1 insertions left in string 1
    }

    // Same 
    if (word1[i] === word2[j]) {
        return minDistanceRecursion(word1, word2, i - 1, j - 1);
    } else {
        // Replace 
        const replaceChar = 1 + minDistanceRecursion(word1, word2, i - 1, j - 1);
        // Insert
        const insertChar = 1 + minDistanceRecursion(word1, word2, i, j - 1);
        // Delete
        const deleteChar = 1 + minDistanceRecursion(word1, word2, i - 1, j);
        return Math.min(replaceChar, Math.min(insertChar, deleteChar));
    }
}