class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> path;
        helper(1, k, n, result, path);
        return result;
    }

    void helper(int i, int size, int target, vector<vector<int>>& result, vector<int>& path) {
        if(target == 0) {
            if(path.size() == size) {
                result.push_back(path);
            }
            return;
        }

        if(i == 10) return;

        // pick 
        if(target >= i) {
            path.push_back(i);
            helper(i+1, size, target-i, result, path);
            path.pop_back();
        }
        // not pick
        helper(i+1, size, target, result, path);
    }
};