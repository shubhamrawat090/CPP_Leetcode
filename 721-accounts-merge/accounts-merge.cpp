class Solution {
    struct DSU {
        vector<int> parent;
        vector<int> rank;
        vector<int> size;

        DSU(int n) {
            parent.resize(n);
            for(int i=0; i<n; i++) {
                parent[i] = i;
            }
            rank.resize(n, 0);
            size.resize(n, 1);
        }

        int find(int u) {
            if(parent[u] == u) return u;
            return parent[u] = find(parent[u]);
        }

        void unionByRank(int u, int v) {
            int pu = find(u), pv = find(v);
            
            if(pu == pv) return; // SAFETY CHECK: Might not be needed

            if(rank[pu] > rank[pv]) {
                parent[pv] = pu;
            } else if(rank[pv] > rank[pu]) {
                parent[pu] = pv;
            } else {
                parent[pv] = pu;
                rank[pu]++;
            }
        }
    };

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // DSU works on numbers and not strings -> map each email to a number
        unordered_map<string, int> emailToId;
        mapEmailToNumbers(accounts, emailToId); // email --> number

        // When I union, I’ll lose track of names… how do I get name back later?
        unordered_map<string, string> emailToName;
        mapEmailToNames(accounts, emailToName); // email --> name

        // Size of DSU == no. of unique emails
        int n = emailToId.size();
        DSU dsu(n); // initialize DSU of size n

        /*
            For:
            ["John", a, b, c]
            You should connect:
            a - b
            a - c   
        */
        addEmailsToDSU(accounts, dsu, emailToId); // First email --> remaining each email

        // {0: [a, b, c]}, 0 = id of a, and the arr[] is the list of emails under the same group
        vector<vector<string>> emailGroups(n);
        groupSameParentEmails(emailToId, dsu, emailGroups);

        // We have same email groups together.
        // Build this: {name: [sortedEmailGroup]}
        vector<vector<string>> ans;
        buildNameToSortedEmails(emailGroups, dsu, emailToName, ans);
        return ans;
    }

    void buildNameToSortedEmails(vector<vector<string>>& emailGroups, DSU& dsu, unordered_map<string, string>& emailToName, vector<vector<string>>& ans) {
        for(vector<string> group: emailGroups) {
            
            if(group.size() == 0) continue; // Skip empty groups

            sort(group.begin(), group.end());
            string firstEmail = group[0];
            string name = emailToName[firstEmail];
            vector<string> nameEmails;
            nameEmails.push_back(name);
            for(string email: group) {
                nameEmails.push_back(email);
            }
            ans.push_back(nameEmails);
        }
    }

    void groupSameParentEmails(unordered_map<string, int> emailToId, DSU& dsu, vector<vector<string>>& emailGroups) {
        // Go through each email and push into same groups
        for(auto it: emailToId) {
            string email = it.first;
            int u = it.second;
            int pu = dsu.find(u);
            emailGroups[pu].push_back(email);
        }
    }

    void addEmailsToDSU(vector<vector<string>>& accounts, DSU& dsu, unordered_map<string, int>& emailToId) {
        for(int i=0; i<accounts.size(); i++) {
            string firstEmail = accounts[i][1];
            int u = emailToId[firstEmail];
            for(int j=2; j<accounts[i].size(); j++) {
                string email = accounts[i][j];
                int v = emailToId[email];
                dsu.unionByRank(u, v);
            }
        }
    }

    void mapEmailToNames(vector<vector<string>>& accounts, unordered_map<string, string>& emailToName) {
        for(int i=0; i<accounts.size(); i++) {
            string name = accounts[i][0];
            for(int j=1; j<accounts[i].size(); j++) {
                string email = accounts[i][j];
                emailToName[email] = name;
            }
        }
    }

    void mapEmailToNumbers(vector<vector<string>>& accounts, unordered_map<string, int>& emailToId) {
        int id = 0;
        for(int i=0; i<accounts.size(); i++) {
            for(int j=1; j<accounts[i].size(); j++) {
                string email = accounts[i][j];
                if(emailToId.find(email) == emailToId.end()) {
                    // not present
                    emailToId[email] = id++;
                }
            }
        }
    }
};