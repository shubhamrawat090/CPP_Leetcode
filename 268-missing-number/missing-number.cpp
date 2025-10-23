class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int i = 0;
        while(i < size) {
            int correctIndex = nums[i];
            if(i != nums[i] && nums[i] < size) {
                swap(nums[i], nums[correctIndex]);
            } else {
                i++;
            }
        }

        // Check i == nums[i] => return i where they don't match
        for(int i=0; i<size; i++) {
            if(i != nums[i]) {
                return i;
            }
        }
        return size;
    }
};