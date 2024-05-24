class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> elemIdxMap;

        for(int i=0; i<nums.size(); i++) {
            int remaining = target - nums[i];
            auto foundItr = elemIdxMap.find(remaining);

            if(foundItr != elemIdxMap.end()) {
                // num, target - num FOUUND
                ans.push_back(i);
                ans.push_back(elemIdxMap[remaining]);
                break;
            } else {
                // NOT FOUND
                elemIdxMap[nums[i]] = i;
            }
        }

        return ans;
    }
};