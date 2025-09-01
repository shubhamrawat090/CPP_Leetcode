/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */

const swap = (nums, i, j) => {
    nums[i] = nums[i] ^ nums[j];
    nums[j] = nums[i] ^ nums[j];
    nums[i] = nums[i] ^ nums[j];
};

const reverse = (nums, start) => {
    let left = start, right = nums.length - 1;
    while (left < right) {
        swap(nums, left, right);
        left++;
        right--;
    }
};

var nextPermutation = function (nums) {
    let pivot = -1;
    for (let i = nums.length - 1; i > 0; i--) {
        if (nums[i - 1] < nums[i]) {
            pivot = i - 1;
            break;
        }
    }

    if (pivot === -1) { // curr permutation is the highest
        // POINT TO NOTE: Here I returned as it is without sorting. In the question smallest was asked if none possible so we reverse it. I forgot it, so need to keep in mind.
        reverse(nums, 0);
        return;
    }

    let successor = -1;
    for (let i = nums.length - 1; i > pivot; i--) {
        if (nums[i] > nums[pivot]) {
            successor = i;
            break;
        }
    }

    // swap nums[pivot] and nums[successor]
    swap(nums, pivot, successor);

    // reverse from pivot + 1, end
    // POINT TO NOTE: Here I did left != right and not left < right which caused TLE as left and right crosses each other and are never equal. It failed in test case [1,1]
    reverse(nums, pivot + 1);
};