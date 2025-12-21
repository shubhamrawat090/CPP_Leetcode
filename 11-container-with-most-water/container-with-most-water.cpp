class Solution {
public:
    int maxArea(vector<int>& input) {
        int n = input.size();
        int left = 0, right = n - 1;
        int maxArea = 0;
        while (left < right) {
            int area = min(input[left], input[right]) * (right - left);
            if (input[left] < input[right]) {
                left++;
            } else {
                right--;
            }
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};