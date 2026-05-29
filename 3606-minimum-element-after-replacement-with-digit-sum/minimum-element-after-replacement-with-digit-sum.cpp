class Solution {
public:
    int minElement(vector<int>& nums) {
        int minVal = INT_MAX;
        for(int num: nums) {
            int digitSum = getDigitSum(num);
            minVal = min(minVal, digitSum);
        }
        return minVal;
    }

    int getDigitSum(int num) {
        int sum = 0;
        while(num) {
            sum += num%10;
            num /= 10;
        }
        return sum;
    }
};