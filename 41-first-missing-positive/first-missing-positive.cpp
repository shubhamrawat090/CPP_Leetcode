class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while (i < n) {
            if (nums[i] <= 0) {
                i++;
            } else {
                int correctPos = nums[i] - 1;
                // cout << "i: " << i << ", nums[i]: " << nums[i] << endl;
                if (correctPos >= n || nums[i] == nums[correctPos]) {
                    i++;
                } else {
                    swap(nums[i], nums[correctPos]);
                }
            }
        }

        int result = n + 1;
        for (int i = 0; i < n; i++) {
            // cout << "** i: " << i << ", nums[i]: " << nums[i] << endl;
            if (nums[i] != i + 1) {
                result = i + 1;
                break;
            }
        }

        return result;
    }
};