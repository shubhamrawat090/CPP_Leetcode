/**
 * @param {string} text1
 * @param {string} text2
 * @return {number}
 */
var longestCommonSubsequence = function (text1, text2) {
    // return lcsRecursive(text1, text2, text1.length - 1, text2.length - 1);
    // const dp = new Array(text1.length).fill().map(() => new Array(text2.length).fill(-1));
    // return lcsMemo(text1, text2, text1.length - 1, text2.length - 1, dp);
    // return lcsTabulate(text1, text2);
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
        prev = [...curr]; ///// KEEP IN MIND TO DO LIKE THIS
    }

    return prev[textLen2];
}

function lcsTabulate(text1, text2) {
    const textLen1 = text1.length, textLen2 = text2.length;
    const dp = new Array(textLen1 + 1).fill().map(() => new Array(textLen2 + 1).fill(-1));
    for (let i = 0; i <= textLen1; i++) {
        dp[i][0] = 0;
    }
    for (let j = 0; j <= textLen2; j++) {
        dp[0][j] = 0;
    }

    for (let i = 1; i <= textLen1; i++) {
        for (let j = 1; j <= textLen2; j++) {
            if (text1[i - 1] === text2[j - 1]) {
                // both match
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                // doesn't match
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[textLen1][textLen2];
}

function lcsMemo(text1, text2, i, j, dp) {
    if (i < 0 || j < 0) {
        return 0;
    }

    if (dp[i][j] !== -1) {
        return dp[i][j];
    }

    if (text1[i] === text2[j]) {
        // both match
        return dp[i][j] = 1 + lcsMemo(text1, text2, i - 1, j - 1, dp);
    } else {
        // doesn't match
        return dp[i][j] = Math.max(lcsMemo(text1, text2, i - 1, j, dp), lcsRecursive(text1, text2, i, j - 1, dp));
    }
}

function lcsRecursive(text1, text2, i, j) {
    if (i < 0 || j < 0) {
        return 0;
    }

    if (text1[i] === text2[j]) {
        // both match
        return 1 + lcsRecursive(text1, text2, i - 1, j - 1);
    } else {
        // doesn't match
        return Math.max(lcsRecursive(text1, text2, i - 1, j), lcsRecursive(text1, text2, i, j - 1));
    }
}