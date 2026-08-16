class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0, right = n-1;
        int maxWater = 0;
        while(left < right) {
            int ht = min(height[left], height[right]);
            int len = right-left;
            int water = ht*len;
            maxWater = max(maxWater, water);

            if(height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxWater;
    }
};