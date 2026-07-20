class Solution {
public:
    int maximumSum(vector<int>& arr) {
        // TODO: Write notes
        int n = arr.size();
        int deletion = 0;
        int noDeletion = arr[0];
        int res = arr[0];
        for (int i = 1; i < n; i++) {
            // KEEP THE curr element, arr[i]
            int v1 = arr[i];
            int v2 = noDeletion + arr[i];
            int v3 = deletion + arr[i];
            // DO NOT KEEP the element, arr[i] -> You need to carry the highest subarray with noDeletions
            int v4 = noDeletion;
            res = max(res, max(max(v1, v2), max(v3, v4)));
            noDeletion = max(v1, v2);
            deletion = max(v3, v4);
        }
        return res;
    }
};