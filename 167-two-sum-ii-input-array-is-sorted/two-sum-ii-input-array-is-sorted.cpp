class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        ans = {0, 0};
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                ans = {left + 1, right + 1};
                break;
            } else if (sum > target) {
                right--;
            } else {
                left++;
            }
        }
        return ans;
    }
};