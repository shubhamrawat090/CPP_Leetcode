class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        unordered_map<int, bool> visited;
        for(int num: nums) {
            visited[num] = false;
        }

        for(int num: nums) {
            if(visited[num] == true) continue;
            // Is it a starting point
            // num-1 exists. Therefore, num is not a starting point
            if(visited.find(num-1) != visited.end()) continue;

            // Now num is a starting point
            int count = 0;
            int val = num;
            while(true) {
                if(visited.find(val) == visited.end()) break;
                count++; // num exists -> count it
                visited[val] = true; // Mark visited so that we don't visit it again
                val++; // try for next val
            }

            longest = max(count, longest);
        }

        return longest;
    }
};