class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> smallerRight = getSmallerRight(heights);
        vector<int> smallerLeft = getSmallerLeft(heights);
        int maxArea = 0;
        for(int i=0; i<heights.size(); i++) {
            int area = heights[i] * (smallerRight[i]-smallerLeft[i]-1);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }

    vector<int> getSmallerRight(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }


    vector<int> getSmallerLeft(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=0; i<n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
};