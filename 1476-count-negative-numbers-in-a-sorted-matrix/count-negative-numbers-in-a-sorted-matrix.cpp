class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for(vector<int> row: grid) {
            count += countSingleRowNegatives(row);
        }
        return count;
    }

    int countSingleRowNegatives(vector<int>& nums) {
        // Binary search for decreasing array
        int N = nums.size();
        if(N == 0 || nums[N-1] >= 0) {
            return 0;
        } 
        int left = 0, right = N - 1, ans = -1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] == 0) {
                ans = mid;
                left = mid + 1;
            } else if(nums[mid] < 0) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if(ans != -1) {
            return N - (ans + 1);
        }
        return N - (right + 1);
    }
};