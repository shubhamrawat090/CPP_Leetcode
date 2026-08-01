class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        deque<int> dq; // stores indices in monotically increasing order of cumulative sum
        vector<long long> cumulativeSum(n, 0);

        int res = INT_MAX;

        for(int i=0; i<n; i++) {
            if(i == 0) {
                cumulativeSum[i] = nums[i];
            } else {
                cumulativeSum[i] = cumulativeSum[i-1] + nums[i];
            }

            if(cumulativeSum[i] >= k) {
                // a possible answer from 0 --> i
                res = min(res, i+1);
            }

            // Can array be shrinked --> from left side --> dq.front()
            while(!dq.empty() && cumulativeSum[i]-cumulativeSum[dq.front()] >= k) {
                // Yes, shrinkable as totalSum - sum till front >= k still
                res = min(res, i-dq.front());
                dq.pop_front();
            }

            // Is the nature monotonic --> 
            // From right->left I will delete all sums which are GREATER THAN current sum    
            while(!dq.empty() && cumulativeSum[i] < cumulativeSum[dq.back()]) {
                dq.pop_back();
            }        

            dq.push_back(i);
        }

        return res == INT_MAX ? -1 : res;
    }
};