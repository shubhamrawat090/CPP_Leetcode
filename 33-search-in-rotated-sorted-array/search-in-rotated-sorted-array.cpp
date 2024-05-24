class Solution {
public:
    int search(vector<int>& nums, int target) {
        // FIND THE PIVOT ELEMENT - where the order breaks
        /*            PIVOT           
                    *            *
                *             *
            *             *
        */
        // If target lies in left range => binary search in 0 => pivot
        // If target lies in right range => binary search in pivot+1 => n-1
        int n = nums.size();

        int pivot = getPivot(nums);
        if(pivot < 0) {
            pivot = 0;
        } else if(pivot >= n) {
            pivot = n-1;
        }
        
        if(nums[0] <= target && pivot-1 >= 0 && nums[pivot-1] >= target) {
            return binarySearch(nums, 0, pivot-1, target);
        } else {
            return binarySearch(nums, pivot, n-1, target);
        }
    }

    int getPivot(vector<int>& nums) {
        int n = nums.size();
        int st=0, ed=n-1;
        while(st < ed) {
            int mid = st + (ed - st)/2;
            
            if(mid+1 < n-1 && nums[mid+1] < nums[mid]) {
                return mid+1;
            } else if(mid-1 >= 0 && nums[mid-1] > nums[mid]) {
                return mid;
            } else {
                // Is it in left increasing or right increasing
                if(nums[mid] > nums[ed]) {
                    st = mid+1;
                } else {
                    ed = mid-1;
                }
            }
        }
        return ed;
    }

    int binarySearch(vector<int>& nums, int st, int ed, int target) {
        while(st <= ed) {
            int mid = st + (ed-st)/2;
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] > target) {
                ed = mid-1;
            } else {
                st = mid+1;
            }
        }
        return -1;
    }
};