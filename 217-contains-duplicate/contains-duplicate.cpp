class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> uniqueNums;
        for(int num: nums) {
            if(!uniqueNums.insert(num).second) {
                return true;
            }
        }
        return false;
    }
};