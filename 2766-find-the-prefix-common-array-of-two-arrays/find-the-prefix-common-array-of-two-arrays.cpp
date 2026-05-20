class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans;
        int n = B.size();
        for (int i = 0; i < n; i++) {
            int common = 0;
            for (int j = 0; j <= i; j++) {
                for (int k = 0; k <= i; k++) {
                    if (B[j] == A[k])
                        common++;
                }
            }
            ans.push_back(common);
        }
        return ans;
    }
};