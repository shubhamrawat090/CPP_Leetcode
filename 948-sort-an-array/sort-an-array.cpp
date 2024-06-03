class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n-1;
        mergeSort(nums, s, e);
        return nums;
    }

    void mergeSort(vector<int>& nums, int s, int e) {
        if(s >= e) return;
        int mid = s + (e-s)/2;
        mergeSort(nums, s, mid);
        mergeSort(nums, mid+1, e);

        mergeSorted(nums, s, mid, e);
    }

    void mergeSorted(vector<int>& nums, int s, int mid, int e) {
        if(s >= e) return;
        if(s == e-1) {
            // only 1 element
            if(nums[s] > nums[e]) {
                swap(nums[s], nums[e]);
            }
            return;
        }
        vector<int> left, right;
        for(int i=s; i<=mid; i++) {
            if(i>=s && i<=e) {
                left.push_back(nums[i]);
            } 
        }
        for(int i=mid+1; i<=e; i++) {
            if(i>=s && i<=e) {
                right.push_back(nums[i]);
            }
        }
        int itr = s, l=0, r=0;
        while(l<left.size() && r<right.size()) {
            if(left[l] < right[r]) {
                nums[itr++] = left[l++];
            } else {
                nums[itr++] = right[r++];
            }
        }
        while(l<left.size()) {
            nums[itr++] = left[l++];
        }
        while(r<right.size()) {
            nums[itr++] = right[r++];
        }
    }
};