class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0] == b[0]) return a[1] < b[1];
            return a[0] > b[0];
        }); // Sort height desc + count asc

        vector<vector<int>> ans;
        for(vector<int>& p: people) {
            int ht = p[0], cnt = p[1];
            ans.insert(ans.begin() + cnt, p);
        }
        return ans;
    }
};