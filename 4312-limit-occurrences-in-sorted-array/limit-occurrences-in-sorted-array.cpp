class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> ans;
        int currElem = nums[0], currCount = 0;
        for(int i=0; i<nums.size(); i++) {
            if(currElem == nums[i]) {
                currCount++;
            } else {
                currElem = nums[i];
                currCount = 1;
            }

            if(currCount <= k) {
                ans.push_back(currElem);
            }
        }
        return ans;
    }
};