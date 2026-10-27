class Solution {
    int floydCycle(vector<int>& nums) {
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        slow = 0;
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }

    int cyclicSort(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i < n) {
            int correctIndex = nums[i] - 1;
            if (correctIndex == n || nums[correctIndex] == nums[i]) {
                i++;
            } else {
                swap(nums[i], nums[correctIndex]);
            }
        }

        int ans = n;
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                ans = nums[i];
                break;
            }
        }
        return ans;
    }

public:
    int findDuplicate(vector<int>& nums) { 
        return floydCycle(nums); 
        // return cyclicSort(nums); 
    }
};