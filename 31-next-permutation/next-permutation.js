/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var nextPermutation = function (nums) {
    let pivot = -1;
    for (let i = nums.length - 1; i > 0; i--) {
        if (nums[i - 1] < nums[i]) {
            pivot = i - 1;
            break;
        }
    }

    console.log("pivot: ", pivot)

    if (pivot === -1) { // curr permutation is the highest
        // return the smallest combination
        let left = 0, right = nums.length - 1;
        while (left < right) {
            nums[left] = nums[left] ^ nums[right];
            nums[right] = nums[left] ^ nums[right];
            nums[left] = nums[left] ^ nums[right];

            left++;
            right--;
        }
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
    nums[pivot] = nums[pivot] ^ nums[successor];
    nums[successor] = nums[pivot] ^ nums[successor];
    nums[pivot] = nums[pivot] ^ nums[successor];

    // reverse from pivot + 1, end
    let left = pivot + 1, right = nums.length - 1;
    while (left < right) {
        nums[left] = nums[left] ^ nums[right];
        nums[right] = nums[left] ^ nums[right];
        nums[left] = nums[left] ^ nums[right];

        left++;
        right--;
    }
};