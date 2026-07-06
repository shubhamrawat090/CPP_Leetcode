class Solution {
private: 
    static bool cmp(vector<int>& a, vector<int>& b) {
        return (a[0] == b[0]) ? (a[1] > b[1]) : (a[0] < b[0]);
    }
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();
        vector<int> coveredInterval(n, false);
        
        for(int curr=0; curr<n-1; curr++) {
            for(int next=curr+1; next<n; next++) {
                if(isMerging(intervals[curr], intervals[next])) coveredInterval[next] = true;
            }
        }

        for(int i=0; i<n; i++) {
            cout<<intervals[i][0]<<", "<<intervals[i][1]<<"\t";
        }

        int covered = 0;
        for(bool c: coveredInterval) {
            if(c) covered++;
        }
        cout<<"\nCovered: "<<covered<<endl;

        return n - covered;
    }

    bool isMerging(vector<int>& curr, vector<int>& next) {
        int a = curr[0], b = curr[1];
        int c = next[0], d = next[1];
        return a <= c && d <= b;
    }
};