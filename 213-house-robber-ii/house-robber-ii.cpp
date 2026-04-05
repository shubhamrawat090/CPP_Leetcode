class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];

        vector<int> robWithFirst(n);
        robWithFirst[0] = nums[0];
        robWithFirst[1] = max(nums[0], nums[1]);

        for(int i=2; i<n-1; i++) {
            robWithFirst[i] = max(robWithFirst[i-1], nums[i] + robWithFirst[i-2]);
        }

        vector<int> robWithoutFirst(n);
        robWithoutFirst[0] = 0;
        robWithoutFirst[1] = nums[1];

        for(int i=2; i<n; i++) {
            robWithoutFirst[i] = max(robWithoutFirst[i-1], nums[i] + robWithoutFirst[i-2]);
        }

        cout<<"\nRobWithFirst: ";
        for(int i=0; i<n; i++) {
            cout<<robWithFirst[i]<<" | ";
        }
        cout<<"\nRobWithoutFirst: ";
        for(int i=0; i<n; i++) {
            cout<<robWithoutFirst[i]<<" | ";
        }

        return max(robWithFirst[n-2], robWithoutFirst[n-1]);
    }
};