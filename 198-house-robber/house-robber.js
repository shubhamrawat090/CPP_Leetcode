/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function (nums) {
    // return robHouseRecursion(nums, 0);
    // const dp = new Array(nums.length).fill(-1);
    // return robHouseMemo(nums, 0, dp);
    return robHouseTabulate(nums);
};

var robHouseTabulate = function (nums) {
    const size = nums.length;
    const dp = new Array(size + 1).fill(-1);
    dp[size] = 0;
    dp[size - 1] = nums[size - 1];

    for (let i = size - 2; i >= 0; i--) {
        // Take curr
        const takeCurr = nums[i] + dp[i + 2];
        // Skip curr
        const skipCurr = dp[i + 1];
        dp[i] = Math.max(takeCurr, skipCurr);
    }

    return dp[0];
}

var robHouseMemo = function (nums, i, dp) {
    if (i >= nums.length) {
        return 0;
    }

    if (dp[i] != -1) {
        return dp[i];
    }

    // Take curr
    const takeCurr = nums[i] + robHouseMemo(nums, i + 2, dp);
    // SKip curr
    const skipCurr = robHouseMemo(nums, i + 1, dp);
    return dp[i] = Math.max(takeCurr, skipCurr);
}

var robHouseRecursion = function (nums, i) {
    if (i >= nums.length) {
        return 0;
    }

    // Take curr
    const takeCurr = nums[i] + robHouseRecursion(nums, i + 2);
    // SKip curr
    const skipCurr = robHouseRecursion(nums, i + 1);
    return Math.max(takeCurr, skipCurr);
}