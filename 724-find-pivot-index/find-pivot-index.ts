function pivotIndex(nums: number[]): number {
    const totalSum = nums.reduce((sum, num) => sum + num, 0);
    let leftSum = 0, rightSum = totalSum;
    let ans = -1;

    for(let i=0; i<nums.length; i++) {
        rightSum -= nums[i];
        if(rightSum == leftSum) {
            ans = i;
            break;
        }
        leftSum += nums[i];
    }

    return ans;
};