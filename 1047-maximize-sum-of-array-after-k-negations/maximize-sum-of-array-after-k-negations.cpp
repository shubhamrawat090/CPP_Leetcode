class Solution {
    struct Compare {
        bool operator()(const int& a, const int& b) {
            // if(a < 0 && b < 0) return a < b;
            // if(a < 0) return a > b;
            // if(b < 0) return a > b;
            return a > b; 
        }
    };

public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, Compare> pq;
        priority_queue<int, vector<int>, Compare> pq_temp;
        for(int num: nums) {
            pq.push(num);
            pq_temp.push(num);
        } 

        // DEBUG: Remove 
        int size = pq.size();
        for(int i=0; i<size; i++) {
            int top = pq_temp.top();
            pq_temp.pop();
            cout<<top<<" ";
        }


        for(int i=0; i<k; i++) {
            int top = pq.top();
            pq.pop();
            pq.push(-top);
        }

        int sum = 0;
        while(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};