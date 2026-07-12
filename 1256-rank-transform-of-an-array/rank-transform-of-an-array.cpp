class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        unordered_map<int, int> elemRank;
        int rank = 1;
        for(int elem: temp) {
            if(elemRank.find(elem) == elemRank.end()) {
                elemRank[elem] = rank++;
            }
        }
        vector<int> ans;
        for(int elem: arr) {
            ans.push_back(elemRank[elem]);
        }
        return ans;
    }
};