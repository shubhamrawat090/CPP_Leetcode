class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int j=1; j<nums.size(); j++) {
            // same ko ignore karo
            // different ko update karo
            if(nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1; // for index i, size = i+1
    }
};