#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp(n); // Temporary array for merging
        mergeSort(nums, temp, 0, n-1);
        return nums;
    }

    void mergeSort(vector<int>& arr, vector<int>& temp, int s, int e) {
        if (s >= e) return;
        int mid = s + (e - s) / 2;
        
        mergeSort(arr, temp, s, mid);
        mergeSort(arr, temp, mid + 1, e);
        
        mergeSortedArr(arr, temp, s, mid, e);
    }

    void mergeSortedArr(vector<int>& arr, vector<int>& temp, int s, int mid, int e) {
        int i = s, j = mid + 1, k = s;
        
        // Merge the two subarrays into temp
        while (i <= mid && j <= e) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }
        
        // Copy any remaining elements from the left subarray
        while (i <= mid) {
            temp[k++] = arr[i++];
        }
        
        // Copy any remaining elements from the right subarray
        while (j <= e) {
            temp[k++] = arr[j++];
        }
        
        // Copy the merged subarray back into the original array
        for (int i = s; i <= e; i++) {
            arr[i] = temp[i];
        }
    }
};
