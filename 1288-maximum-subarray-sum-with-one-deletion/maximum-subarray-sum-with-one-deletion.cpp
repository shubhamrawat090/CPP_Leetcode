class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int maxSum = arr[0];
        int del = 0;
        int nonDel = arr[0];
        for(int i=1; i<n; i++) {
            // Take num
            int v1 = arr[i];
            int v2 = del + arr[i];
            int v3 = nonDel + arr[i];

            // Remove num
            int v4 = nonDel;

            del = max(v2, v4);
            nonDel = max(v1, v3);

            maxSum = max(maxSum, max(del, nonDel));
        }
        return maxSum;
    }
};