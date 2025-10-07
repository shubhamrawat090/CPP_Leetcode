class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        int n = nums.length;
        int i = 0;
        List<Integer> ans = new ArrayList<Integer>();

        while(i < n) {
            int correctIndex = nums[i] - 1;
            if(nums[i] != nums[correctIndex]) {
                int temp = nums[i];
                nums[i] = nums[correctIndex];
                nums[correctIndex] = temp;
            } else {
                i++;
            }
        }

        for(int j=0; j<n; j++) {
            if(j + 1 != nums[j]) {
                ans.add(j + 1);
            }
        }

        return ans;
    }
}