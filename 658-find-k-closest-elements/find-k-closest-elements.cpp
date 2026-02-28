class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int left = 0, right = n - 1;
        while(left < right && right - left + 1 > k) {
            int leftDiff = abs(x - arr[left]);
            int rightDiff = abs(arr[right] - x);
            if(leftDiff > rightDiff) {
                left++;
            } else {
                right--;
            }
        } 

        vector<int> ans;
        for(int i=left; i <= right; i++) {
            ans.push_back(arr[i]);
        }
        return ans;
    }
};