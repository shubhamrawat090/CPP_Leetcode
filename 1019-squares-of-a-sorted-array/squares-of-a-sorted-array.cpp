class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int minVal = INT_MAX, maxVal = INT_MIN;
        unordered_map<int, int> valSquare;
        unordered_map<int, int> valFreq;
        for(int num: nums) {
            minVal = min(minVal, abs(num));
            maxVal = max(maxVal, abs(num));
            valSquare[abs(num)] = num * num;
            valFreq[abs(num)]++;
        }

        vector<int> ans;
        for(int i=minVal; i<=maxVal; i++) {
            if(valSquare.find(i) != valSquare.end()) {
                ans.push_back(valSquare[i]);
                valFreq[i]--;
                if(valFreq[i] != 0) {
                    // This element occurs more than once -> move i back to re-count
                    i--;
                }
            }
        }
        return ans;
    }
};