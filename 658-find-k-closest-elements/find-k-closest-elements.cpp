class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // APPROACH 1
        // push -> val, diff = abs(x-val) in a map
        // if map.size() < k, keep pushing in map
        // if map.size() == k, traverse the map to find val with HIGHEST diff
        // delete the element with highest diff
        // push the new val in the map

        // APPROACH 2 - 2 ptr
        // place 1 ptr at left and at right
        // if num of elements from left -> right == k then just return elements
        // from left to right if num of elements from left -> right > k, then
        // check if abs(left - x) > abs(right - x) => left++ else right--
        int n = arr.size();
        int left = 0, right = n - 1;
        while (left < right && (right - left + 1) > k) {
            int leftDiff = abs(arr[left] - x), rightDiff = abs(arr[right] - x);
            if (rightDiff >= leftDiff) {
                right--;
            } else {
                left++;
            }
        }

        // return elements from left to right
        vector<int> ans;
        for (int i = left; i <= right; i++) {
            ans.push_back(arr[i]);
        }
        return ans;
    }
};