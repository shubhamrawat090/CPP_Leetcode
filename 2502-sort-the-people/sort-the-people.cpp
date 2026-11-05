struct People {
    int height;
    string name;
};

bool cmp(const People& a, const People& b) { return a.height > b.height; }

class Solution {

public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        People A[n];
        for (int i = 0; i < n; i++) {
            A[i].height = heights[i];
            A[i].name = names[i];
        }

        sort(A, A + n, cmp);

        vector<string> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = A[i].name;
        }

        return ans;
    }
};