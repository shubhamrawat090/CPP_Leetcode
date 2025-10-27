class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i =0, N = nums.size();
        while(i < N) {
            int correctIndex = nums[i] - 1;
            if(nums[i] != nums[correctIndex]) {
                swap(nums[i], nums[correctIndex]);
            } else {
                i++;
            }
        }

        for(int j=0; j<N; j++) {
            if(j + 1 != nums[j]) {
                return nums[j];
            }
        }

        return -1;
    }
};