/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    const prefixArr = [];

    let product = 1;
    for(let i=0; i<nums.length; i++) {
        const num = nums[i];
        prefixArr[i] = product;
        product *= num;
    }

    const result = [];
    product = 1;
    for(let i=nums.length - 1; i>=0; i--) {
        const num = nums[i];
        const postfixValAtI = product;
        result[i] = prefixArr[i] * postfixValAtI;
        product *= num;
    }

    return result;
};