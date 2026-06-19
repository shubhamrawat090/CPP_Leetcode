class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nextSmallerRight(n, 0);
        getNextSmallerRight(heights, nextSmallerRight, n);

        vector<int> nextSmallerLeft(n, 0);
        getNextSmallerLeft(heights, nextSmallerLeft, n);
        
        int largestArea = 0;
        for(int i=0; i<n; i++) {
            int ht = heights[i];
            int wt = nextSmallerRight[i] - nextSmallerLeft[i] - 1;
            int area = ht * wt;
            largestArea = max(area, largestArea);
        }

        return largestArea;
    }

    void getNextSmallerRight(vector<int>& heights, vector<int>& nextSmaller, int& n) {
        stack<int> st;
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            nextSmaller[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }

    void getNextSmallerLeft(vector<int>& heights, vector<int>& nextSmaller, int& n) {
        stack<int> st;
        for(int i=0; i<n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            nextSmaller[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }
};