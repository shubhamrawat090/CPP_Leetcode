class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> elems;
        for(int num: nums) {
            if(elems.count(num)) return true;
            elems.insert(num);
        }
        return false;
    }
};