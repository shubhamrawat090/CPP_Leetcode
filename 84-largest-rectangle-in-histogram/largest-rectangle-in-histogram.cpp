class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      // get arr of first smaller to left  
      // get arr of first smaller to right  
      // for arr[i] => AREA = height * length = arr[i] * (nextSmall[i]-prevSmall[i]-1)
      int n = heights.size();
      vector<int> nextSmall = getSmallArr(heights, n, "next");
      vector<int> prevSmall = getSmallArr(heights, n, "prev");

      int maxArea = -1;
      for(int i=0; i<n; i++) {
        int nextSmallElem = nextSmall[i] == -1 ? n : nextSmall[i];
        int prevSmallElem = prevSmall[i] == -1 ? -1 : prevSmall[i];
        int currArea = heights[i] * (nextSmallElem-prevSmallElem-1);
        maxArea = max(maxArea, currArea);
      }

      return maxArea;
    }

private:
    vector<int> getSmallArr(vector<int>& arr, int n, string type) {
        vector<int> ans(n, -1);
        stack<int> stk; // NOTE: stores index instead of element
        stk.push(-1);

        if(type == "next") {
            // next small
            for(int i=n-1; i>=0; i--) {
                int minFound = -1;
                // POP - till you find a topElem < arr[i]
                while(!stk.empty()) {
                    int top = stk.top();
                    int topElem = top == -1 ? -1 : arr[top];
                    if(topElem < arr[i]) {
                        minFound = top;
                        break;
                    } else {
                        stk.pop();
                    }
                }
                // add elem < arr[i] at ans[i]
                ans[i] = minFound;
                // push arr[i] in stk
                stk.push(i);
            } 
        } else {
            // prev small
            for(int i=0; i<n; i++) {
                int minFound = -1;
                // POP - till you find a topElem < arr[i]
                while(!stk.empty()) {
                    int top = stk.top();
                    int topElem = top == -1 ? -1 : arr[top];
                    if(topElem < arr[i]) {
                        minFound = top;
                        break;
                    } else {
                        stk.pop();
                    }
                }
                // add elem < arr[i] at ans[i]
                ans[i] = minFound;
                // push arr[i] in stk
                stk.push(i);
            } 
        }

        return ans;
    }
};