class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int itr = 0;
        int curr = 0;
        int n = nums.size();
        for (int n : nums)
            cout << n << " ";
        cout << endl;
        while (itr < n) {
            int nextGr = n;
            for (int i = curr + 1; i < n; i++) {
                if (nums[i] > nums[curr]) {
                    nextGr = i;
                    break;
                }
            }
            // cout << "ARR: ";
            // for (int n : nums)
            //     cout << n << " ";
            // cout << "\ncurr, itr, nextGr: " << curr << ", " << itr << ", "
            //      << nextGr << endl;
            if (nextGr == n)
                break;
            swap(nums[++itr], nums[nextGr]);
            curr = itr;
        }

        for (int n : nums)
            cout << n << " ";

        return itr + 1;
    }
};