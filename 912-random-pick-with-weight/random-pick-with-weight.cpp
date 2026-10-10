class Solution {
    /*
      [1, 2, 3]
        +1    +2      +3s
      0....1......3........6

      for 1 bucket is (0, 1]
      for 2 bucket is (1, 3]
      for 3 bucket is (3, 6]

      APPROACH:
      Generate a random number between 0->totalSum(6 here)
      FIND WHICH BUCKET THE NUMBER BELONGS TO -> We can use Binary search
      here(upper_bound)
    */

    vector<int> wts;
    int sum;

    int upperBound(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int ans = n;
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] > target) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

public:
    Solution(vector<int>& w) {
        sum = 0;
        int n = w.size();
        wts.resize(n, 0);
        for (int i = 0; i < n; i++) {
            sum += w[i];
            wts[i] = sum;
        }
    }

    int pickIndex() {
        int randomVal = rand() % sum; // Keep the random within sum only

        // Find which bucket it belongs to
        return upperBound(wts, randomVal);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */