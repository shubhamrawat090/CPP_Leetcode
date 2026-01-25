class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int i=0;
        while(i < n) {
            int correctIndex = nums[i];
            if(nums[i] >= n || nums[i] == i) {
                i++;
            } else {
                swap(nums[i], nums[correctIndex]);
            }
        }
        
        for(int i=0; i<n; i++) {
            if(i != nums[i]) return i;
        }
        return n;
    }
};