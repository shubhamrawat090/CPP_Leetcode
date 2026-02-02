class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0, high = numbers.size() - 1;
        vector<int> ans;
        while(low < high) {
            int sum = numbers[low] + numbers[high];
            if(sum == target) {
                ans = {low + 1, high + 1};
                break;
            } else if(sum > target) {
                high--;
            } else {
                low++;
            }
        }
        return ans;
    }
};