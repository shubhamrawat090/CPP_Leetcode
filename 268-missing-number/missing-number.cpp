class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0, N = nums.size();
        // Rearrange - Make arr[i] = i
        while(i < N) {
            int correctIndex = nums[i];
            if(i != nums[i] && nums[i] < N) {
                swap(nums[i], nums[correctIndex]);
            } else {
                i++;
            }
        }

        // Check - if arr[i] == i
        for(int j=0; j<N; j++) {
            if(nums[j] != j) {
                return j;
            }
        }

        // If no value is missing - 0 1 2 3. Then ans is 4 i.e. N
        return N;
    }
};