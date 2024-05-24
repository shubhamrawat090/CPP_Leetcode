class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int st=0, ed=n-1;

        while(st < ed) {
            int mid = st + (ed - st)/2;
            
            if(mid+1 < n-1 && nums[mid+1] < nums[mid]) {
                return nums[mid + 1];
            } else if(mid-1 >= 0 && nums[mid-1] > nums[mid]) {
                return nums[mid];
            } else {
                // Is it in left increasing or right increasing
                if(nums[mid] > nums[ed]) {
                    st = mid+1;
                } else {
                    ed = mid-1;
                }
            }
        }

        return nums[st]; // nums[ed]
    }
};