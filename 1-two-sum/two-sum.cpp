class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> elems;
        for(int i=0; i<n; i++) {
            int num = nums[i];
            int toFind = target - num;
            if(elems.find(toFind) != elems.end()) {
                return {i, elems[toFind]};
            }
            elems[num] = i;
        }
        return {-1, -1};
    }
};