class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, leadingCount = 0;
        for(int num: nums) {
            if(leadingCount == 0) {
                candidate = num;
            }

            if(candidate == num) {
                leadingCount++;
            } else {
                leadingCount--;
            }
        }
        return candidate;
    }
};