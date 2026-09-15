class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nextSmallerLeft = getNextSmallerLeft(heights);
        vector<int> nextSmallerRight = getNextSmallerRight(heights);

        int maxArea = 0;

        int n = heights.size();
        for (int i = 0; i < n; i++) {
            int height = heights[i];
            int length = nextSmallerRight[i] - nextSmallerLeft[i] - 1;
            int area = height * length;
            maxArea = max(area, maxArea);
            cout << endl;
        }

        return maxArea;
    }

    vector<int> getNextSmallerRight(vector<int>& heights) {
        int n = heights.size();
        vector<int> result(n, 0);
        stack<int> stk;

        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }

            int nextSmaller = stk.empty() ? n : stk.top();
            result[i] = nextSmaller;
            stk.push(i);
        }

        return result;
    }

    vector<int> getNextSmallerLeft(vector<int>& heights) {
        int n = heights.size();
        vector<int> result(n, 0);
        stack<int> stk;

        for (int i = 0; i < n; i++) {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }

            int nextSmaller = stk.empty() ? -1 : stk.top();
            result[i] = nextSmaller;
            stk.push(i);
        }

        return result;
    }
};