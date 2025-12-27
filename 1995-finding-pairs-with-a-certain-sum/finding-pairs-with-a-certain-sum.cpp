class FindSumPairs {
    vector<int> nums1, nums2;
    unordered_map<int, int> nums1Freq, nums2Freq;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for(int i=0; i<this->nums1.size(); i++) {
            nums1Freq[nums1[i]]++;
        }
        for(int i=0; i<this->nums2.size(); i++) {
            nums2Freq[nums2[i]]++;
        }
    }
    
    void add(int index, int val) {
        if(index >= nums2.size()) return;
        int oldVal = nums2[index];
        nums2Freq[oldVal]--;
        nums2[index] += val;
        int newVal = nums2[index];
        nums2Freq[newVal]++;
    }
    
    int count(int tot) {
        // iterate in nums2Freq (NOTE: and not in nums2 arr to optimize even further)
        // find tot - nums2[i] freq in the map of nums1 and add to count
        // We did this because nums1 doesn't change at all
        // Therefore, sorting doesn't make sense and is expensive.
        int count = 0;
        for(auto &[val, freq]: nums2Freq) {
            int searchVal = tot - val;
            int matchCount = (nums1Freq[searchVal] * freq);
            count += matchCount;
        }
        return count;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */