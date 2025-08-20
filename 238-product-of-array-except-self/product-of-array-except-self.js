/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    const prefixArr = [];
    const postfixArr = [];

    let product = 1;
    for(let i=0; i<nums.length; i++) {
        const num = nums[i];
        prefixArr[i] = product;
        product *= num;
    }

    product = 1;
    for(let i=nums.length - 1; i>=0; i--) {
        const num = nums[i];
        postfixArr[i] = product;
        product *= num;
    }

    const result = [];
    for(let i=0; i<nums.length; i++) {
        result[i] = prefixArr[i] * postfixArr[i];
    }

    return result;
};