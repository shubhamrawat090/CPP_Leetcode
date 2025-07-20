/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    let sum = 0, n = nums.length;
    for(let i=0; i<n; i++) {
        sum = sum ^ nums[i] ^ i;
    }
    sum = sum ^ n; // Do it with the last missing number as well
    return sum;
};