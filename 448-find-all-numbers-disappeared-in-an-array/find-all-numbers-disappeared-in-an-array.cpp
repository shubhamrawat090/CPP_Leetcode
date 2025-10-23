class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size = nums.size();
        int i = 0;
        while(i < size) {
            int correctIndex = nums[i] - 1;
            if(nums[correctIndex] != nums[i]) {
                // swap(nums[i], nums[correctIndex]);
                int temp = nums[i];
                nums[i] = nums[correctIndex];
                nums[correctIndex] = temp;
            } else {
                i++;
            }
        }

        // Check
        vector<int> ans;
        for(int j=0; j<size; j++) {
            if(j + 1 != nums[j]) {
                ans.push_back(j + 1);
            }
        }

        return ans;
    }
};