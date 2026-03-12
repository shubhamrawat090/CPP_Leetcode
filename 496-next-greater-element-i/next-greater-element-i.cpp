class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // get nextGreater[] for nums2
        // for nums1[i], get the position of nums1[i] in nums2, instead of iterating you can use a map
        // use the nextGreater[] to get the position of nextGreater

        unordered_map<int, int> elemIdx;
        int m = nums1.size(), n = nums2.size();
        for(int i=0; i<n; i++) {
            elemIdx[nums2[i]] = i;
        }

        vector<int> nextGreater(n);
        // TODO: generate this array
        stack<int> st;
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && nums2[i] >= st.top()) {
                st.pop();
            }

            // You can't push back because the array would be in reverse
            nextGreater[i] = st.empty() ? -1 : st.top();

            st.push(nums2[i]);
        }

        for(int i=0; i<n; i++) {
            cout<<nextGreater[i]<<" ";
        }
        vector<int> ans;
        for(int i=0; i<m; i++) {
            int val = nums1[i];
            int idx = elemIdx[val];
            int greater = nextGreater[idx];
            ans.push_back(greater);
        }

        return ans;
    }
};