class Solution {
private:
    vector<int> getSmallerAreaRight(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return ans;
    }

    vector<int> getSmallerAreaLeft(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i=0; i<n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> smallerAreaLeft = getSmallerAreaLeft(heights);
        vector<int> smallerAreaRight = getSmallerAreaRight(heights);

        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            int height = heights[i];
            int width = smallerAreaRight[i] - smallerAreaLeft[i] - 1;
            int area = height * width;
            maxArea = max(area, maxArea);
        }

        return maxArea;
    }
};