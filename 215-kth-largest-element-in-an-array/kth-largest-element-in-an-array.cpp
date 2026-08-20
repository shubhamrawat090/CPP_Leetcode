class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = n-1;
        // After sorting, kth element would be at index n-k 
        int targetIndex = n - k;
        while(left <= right) {
            int randomIdxInRange = left + rand() % (right - left + 1);
            // Like quicksort, elem < nums[pivotIndex]
            // ON LEFT AND GREATER ON RIGHT
            int pivotIndex = partition(nums, left, right, randomIdxInRange);
            if(pivotIndex == targetIndex) {
                // This random index same as target index
                // This means that the element here is same as kth largest element
                return nums[pivotIndex];
            } else if(pivotIndex < targetIndex) {
                // Search on the right side
                left = pivotIndex + 1;
            } else {
                right = pivotIndex - 1;
            }
        }

        return -1;
    }

    int partition(vector<int>& nums, int left, int right, int pivotIndex) {
        int pivotElem = nums[pivotIndex];

        // store this pivot element at last
        swap(nums[right], nums[pivotIndex]);

        // Push all elements < pivotElem on left of pivotIndex
        int storeIndex = left;

        // Scan left->right and store all elements < pivotElement on nums[storeIndex].
        // And move storeIndex to 1 right,
        // This makes all elements from left->storeIndex < pivotElement
        for(int i=left; i<right; i++) {
            if(nums[i] < pivotElem) {
                swap(nums[i], nums[storeIndex]);
                storeIndex++;
            }
        }

        int realPivotIndex = storeIndex; // Real position of pivotElem as if nums were sorted

        // Put the pivotElem back from last to realPivotIndex
        swap(nums[right], nums[realPivotIndex]);

        return realPivotIndex;
    }
};