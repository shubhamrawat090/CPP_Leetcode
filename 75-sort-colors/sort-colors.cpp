class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        quickSort(nums, low, high);
    }

    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        if (low >= high) {
            return;
        }

        int placedElemIdx = partition(arr, low, high);
        quickSort(arr, low, placedElemIdx - 1);
        quickSort(arr, placedElemIdx + 1, high);
    }

    int partition(vector<int>& arr, int low, int high) {
        // GIST: Make sure that all elem < pivot are on LEFT
        // and all elem > pivot are on right

        // ASSUME low to be pivot
        int pivot = arr[low];
        int i = low + 1, j = high;

        while (i <= j) {
            // Move i to right till arr[i] < pivot
            while (i <= j && arr[i] < pivot)
                i++;

            // Move j to left till arr[j] > pivot
            while (i <= j && arr[j] > pivot)
                j--;

            if (i <= j) {
                // Still i and j haven't met
                // MEANS: we go elem arr[i] > pivot and arr[j] < pivot
                swap(arr[i], arr[j]);
                i++, j--;
            }
        }

        // Everything is swapped and j is where pivot should be ideally
        // But right now pivot is at low. So, swap(arr[low], arr[j])
        swap(arr[low], arr[j]);

        return j; // Return the index where correct elem(pivot) has been placed
    }
};