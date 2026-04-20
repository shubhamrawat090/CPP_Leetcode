class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxDist = 0;
        int n = colors.size();
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                if(colors[j] != colors[i]) {
                    maxDist = max(maxDist, j-i);
                }
            }
        }

        for(int i=n-1; i>=1; i--) {
            for(int j=i-1; j>=0; j--) {
                if(colors[j] != colors[i]) {
                    maxDist = max(maxDist, i-j);
                }
            }
        }

        return maxDist;
    }
};