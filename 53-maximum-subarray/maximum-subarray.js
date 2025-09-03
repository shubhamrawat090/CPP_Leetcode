/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    let maxSum = nums[0], currSum = 0;
    for(let i=0; i<nums.length; i++) {
        currSum += nums[i];
        maxSum = Math.max(maxSum, currSum);
        if(currSum < 0) {
            currSum = 0;
        }
    }
    return maxSum;
};