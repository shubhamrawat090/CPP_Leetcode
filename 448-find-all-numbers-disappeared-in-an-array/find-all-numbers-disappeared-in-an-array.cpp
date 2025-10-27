class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int N = nums.size(), i = 0;
        while(i < N) {
            int correctIndex = nums[i] - 1;
            if(nums[i] != nums[correctIndex]) { // CHECK FOR THE VALUES TO BE CORRECT
                swap(nums[i], nums[correctIndex]);
            } else {
                i++;
            }
        }

        vector<int> ans;
        for(int j=0; j<N; j++) {
            if(j + 1 != nums[j]) {
                ans.push_back(j + 1);
            }
        }
        return ans;
    }
};