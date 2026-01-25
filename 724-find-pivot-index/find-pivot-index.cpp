class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int leftSum = 0, rightSum = 0, totalSum = 0;
        for(int num: nums) {
            totalSum += num;
        }
        rightSum = totalSum;
        for(int i=0; i<n; i++) {
            cout<<"-- Before --"<<endl;
            cout<<"(i, leftSum, rightSum) "<<i<<","<<leftSum<<","<<rightSum<<endl;
            if(i == 0) {
                leftSum += 0;
            } else {
                leftSum += nums[i-1];
            }
            
                rightSum -= nums[i];

            cout<<"-- After --"<<endl;
            cout<<"(i, leftSum, rightSum) "<<i<<","<<leftSum<<","<<rightSum<<endl<<endl;
            if(leftSum == rightSum) {
                return i;
            }
        }
        return -1;
    }
};