class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        vector<int> cooldown(26, -1);
        // vector<string> taskList;
        int taskCount = 0;
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
                    if (cooldown[temp - 'A'] == -1 || cooldown[temp - 'A'] >= n) {
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
                // taskList.push_back(str);
                taskCount++;
                freq[ch - 'A']--;
                // increase values in cooldown queue
                for (int i = 0; i < 26; i++) {
                    if (cooldown[i] != -1)
                        cooldown[i]++;
                }

                cooldown[ch - 'A'] = 0; // Reset for cooldown

                if (freq[ch - 'A'] == 0)
                    cooldown[ch - 'A'] = -1; // remove from queue
            } else {
                // taskList.push_back("idle");
                taskCount++;
                // increase values in cooldown queue
                for (int i = 0; i < 26; i++) {
                    if (cooldown[i] != -1)
                        cooldown[i]++;
                }
            }
        }
        
        // return taskList.size();
        return taskCount;
    }
};