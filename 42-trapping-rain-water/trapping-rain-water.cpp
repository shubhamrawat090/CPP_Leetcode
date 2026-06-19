class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> greatestRight = getGreatestRight(height, n);
        vector<int> greatestLeft = getGreatestLeft(height, n);
        int totalWaterTrapped = 0;
        for(int i=0; i<n; i++) {
            int leftGr = greatestLeft[i];
            int rightGr = greatestRight[i];
            if(leftGr < height[i] || rightGr < height[i]) continue;
            int ht = min(leftGr, rightGr) - height[i];
            totalWaterTrapped += ht;
        }
        return totalWaterTrapped;
    }

    vector<int> getGreatestLeft(vector<int>& height, int& n) {
        int greatest = 0;
        vector<int> ans(n, 0);
        for(int i=0; i<n; i++) {
            ans[i] = greatest;
            greatest = max(greatest, height[i]);
        }
        return ans;
    }

    vector<int> getGreatestRight(vector<int>& height, int& n) {
        int greatest = 0;
        vector<int> ans(n, 0);
        for(int i=n-1; i>=0; i--) {
            ans[i] = greatest;
            greatest = max(greatest, height[i]);
        }
        return ans;
    }
};