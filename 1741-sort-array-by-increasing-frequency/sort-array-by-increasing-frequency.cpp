struct FreqMap {
    int val;
    int freq;
};

bool cmp(const FreqMap& a, const FreqMap& b) {
    if(a.freq != b.freq) return a.freq < b.freq;
    return a.val > b.val;
}

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int num: nums) freq[num]++;

        int n = nums.size();
        FreqMap A[n];
        for(int i=0; i<n; i++) {
            A[i].val = nums[i];
            A[i].freq = freq[nums[i]];
        }

        sort(A, A + n, cmp);

        vector<int> ans(n);
        for(int i=0; i<n; i++) {
            ans[i] = A[i].val;
        }

        return ans;
    }
};