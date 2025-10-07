function findDisappearedNumbers(nums: number[]): number[] {
    let n = nums.length;
    let i = 0;
    const ans: number[] = [];

    while (i < n) {
        let correctIndex = nums[i] - 1;
        if (nums[i] != nums[correctIndex]) {
            let temp = nums[i];
            nums[i] = nums[correctIndex];
            nums[correctIndex] = temp;
        } else {
            i++;
        }
    }

    for (let j = 0; j < n; j++) {
        if (j + 1 != nums[j]) {
            ans.push(j + 1);
        }
    }

    return ans;
};