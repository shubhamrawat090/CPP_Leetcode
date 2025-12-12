class Solution {
public:
    int maxArea(vector<int>& height) {
        // 2 pointers - start and end
        // calculate area - min_height * dist
        // keep track of maxArea
        // always keep the longer height line and discard the shorter line
        int left = 0, right = height.size() - 1;
        int ans = 0;
        while(left < right) {
            int area = min(height[left], height[right]) * (right - left);
            ans = max(area, ans);
            if(height[left] > height[right]) {
                right--;
            } else {
                left++;
            }
        }
        return ans;
    }
};