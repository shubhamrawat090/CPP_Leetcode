class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int i = 0, n = nums.size();
        while(i < n) {
            int correctIndex = nums[i] - 1;
            if(nums[i] != nums[correctIndex]) {
                swap(nums[i], nums[correctIndex]);
            } else {
                i++;
            }
        }

        vector<int> ans;
        for(int j=0; j<n; j++) {
            if(j+1 != nums[j]) {
                ans.push_back(nums[j]);
            }
        }

        return ans;
    }
};