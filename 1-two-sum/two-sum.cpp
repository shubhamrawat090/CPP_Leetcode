class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> temp;
        for(int i=0; i<nums.size(); i++) {
            int needed = target - nums[i];
            if(temp.contains(needed)) {
                return {temp[needed], i};
            } else {
                temp[nums[i]] = i;
            }
        }
        return {};
    }
};