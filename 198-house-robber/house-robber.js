/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    // return robHouseRecursion(nums, 0);
    const dp = new Array(nums.length).fill(-1);
    return robHouseMemo(nums, 0, dp);
};

var robHouseMemo = function(nums, i, dp) {
    if(i >= nums.length) {
        return 0;
    }

    if(dp[i] != -1) {
        return dp[i];
    }

    // Take curr
    const takeCurr = nums[i] + robHouseMemo(nums, i+2, dp);
    // SKip curr
    const skipCurr = robHouseMemo(nums, i+1, dp);
    return dp[i] = Math.max(takeCurr, skipCurr);
}

var robHouseRecursion = function(nums, i) {
    if(i >= nums.length) {
        return 0;
    }

    // Take curr
    const takeCurr = nums[i] + robHouseRecursion(nums, i+2);
    // SKip curr
    const skipCurr = robHouseRecursion(nums, i+1);
    return Math.max(takeCurr, skipCurr);
}