/**
 * @param {number[]} nums
 * @return {number}
 */
var lengthOfLIS = function(nums) {
    // return lenLISRecursive(nums, 0, -1);
    const dp = new Array(nums.length).fill().map(() => new Array(nums.length + 1).fill(-1));
    return lenLISMemo(nums, 0, -1, dp);
};

function lenLISMemo(nums, i, prevIdx, dp) {
    if(i === nums.length) {
        return 0;
    }

    if(dp[i][prevIdx+1] !== -1) {
        return dp[i][prevIdx+1];
    }

    // NOT TAKE
    const notTake = 0 + lenLISMemo(nums, i+1, prevIdx, dp);

    // TAKE
    let take = 0;
    if(prevIdx == -1 || nums[i] > nums[prevIdx]) {
        take = 1 + lenLISMemo(nums, i+1, i, dp);
    }

    return dp[i][prevIdx+1] = Math.max(take, notTake);
}

function lenLISRecursive(nums, i, prevIdx) {
    if(i === nums.length) {
        return 0;
    }

    // NOT TAKE
    const notTake = 0 + lenLISRecursive(nums, i+1, prevIdx);

    // TAKE
    let take = 0;
    if(prevIdx == -1 || nums[i] > nums[prevIdx]) {
        take = 1 + lenLISRecursive(nums, i+1, i);
    }

    return Math.max(take, notTake);
}