class Solution {
public:
    int maxDistance(vector<int>& colors) {
        // B Y G Y G
        // 0 1 2 3 4
        // When going left->right, I can take distance b/w 0(B) to 4(G). ANYTHING IN BETWEEN I IGNORE
        // When going right->left, I can take distance b/w 4(G) to 0(B). ANYTHING IN BETWEEN I IGNORE
        // APROACH: left->right, i=0, j=n-1, j ko chhota karo till you get a different color from arr[i]
        // APROACH: right->left, i=0, j=n-1, i ko bada karo till you get a different color from arr[j]

        int n = colors.size();
        int i=0, j=n-1;
        while(i<=j && colors[i] == colors[j]) {
            j--;
        }
        // cout<<"i,j: "<<i<<","<<j<<endl;
        int ans = j-i;

        j = n-1; // reset j at last, i is already at 0
        while(i<=j && colors[j] == colors[i]) {
            i++;
        }
        ans = max(ans, j-i);
        // cout<<"i,j: "<<i<<","<<j<<endl;

        return ans;
    }
};