class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        vector<int> curr(26, -1);
        vector<string> taskList;
        for (char ch : tasks) {
            freq[ch - 'A']++;
        }

        while (true) {
            // Get max value
            char ch = '\0';
            bool valFound = false;
            int maxVal = 0;
            for (int i = 0; i < 26; i++) {
                if (freq[i] > maxVal) {
                    valFound = true;
                    char temp = i + 'A';
                    if (curr[temp - 'A'] == -1 || curr[temp - 'A'] >= n) {
                        maxVal = freq[i];
                        ch = i + 'A';
                    }
                }
            }
            if (!valFound)
                break; // no tasks remaining

            // ch == '\0' means that no task found, all on cooldown
            if (ch != '\0') {
                string str;
                str.push_back(ch);
                taskList.push_back(str);
                freq[ch - 'A']--;
                // increase values in curr queue
                for (int i = 0; i < 26; i++) {
                    if (curr[i] != -1)
                        curr[i]++;
                }

                curr[ch - 'A'] = 0; // Reset for curr

                if (freq[ch - 'A'] == 0)
                    curr[ch - 'A'] = -1; // remove from queue
            } else {
                taskList.push_back("idle");
                // increase values in curr queue
                for (int i = 0; i < 26; i++) {
                    if (curr[i] != -1)
                        curr[i]++;
                }
            }
        }

        for(string& task: taskList) {
            cout<<task<<" ";
        }
        return taskList.size();
    }
};