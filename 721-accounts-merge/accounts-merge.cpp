class Solution {
    struct DSU {
        vector<int> parent;
        vector<int> rank;
        DSU(int n) {
            rank.resize(n, 0);
            parent.resize(n);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int find(int u) {
            if (parent[u] == u)
                return u;
            return parent[u] = find(parent[u]);
        }

        void unionByRank(int u, int v) {
            int pu = find(u);
            int pv = find(v);

            if (rank[pu] > rank[pv]) {
                parent[pv] = pu;
            } else if (rank[pu] < rank[pv]) {
                parent[pu] = pv;
            } else {
                parent[pu] = pv;
                rank[pv]++;
            }
        }
    };

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        // Unique Emails list
        // Email -> name map
        // Email -> assign unique ID num
        // For a list of email [a,b,c]. I take a as (u) and b,c as (v)
        // FORM DSU by unionByRank(u, v)
        // Separate same group emails again.
        // Add names to them as well.
        // Return the list
        unordered_set<string> uniqueEmails = getUniqueEmails(accounts);
        unordered_map<string, string> emailToName = getEmailToName(accounts);
        unordered_map<string, int> emailToID = getEmailToID(accounts);

        int n = uniqueEmails.size();
        DSU dsu = createDSU(n, accounts, emailToID);

        vector<vector<string>> sameGroupEmails =
            getSameGroupEmails(uniqueEmails, dsu, emailToID);
        return addNamesToEmailList(sameGroupEmails, emailToName);
    }

    vector<vector<string>> addNamesToEmailList(vector<vector<string>>& sameGroupEmails, unordered_map<string, string> emailToName) {
        vector<vector<string>> ans;
        for(auto& emailGroup: sameGroupEmails) {
            if(emailGroup.empty()) continue;
            sort(emailGroup.begin(), emailGroup.end());
            vector<string> account;
            string firstEmail = emailGroup[0];
            string name = emailToName[firstEmail];
            account.push_back(name);
            for(auto& email: emailGroup) {
                account.push_back(email);
            }
            ans.push_back(account);
        }
        return ans;
    }

    vector<vector<string>> getSameGroupEmails(unordered_set<string>& uniqueEmails, DSU& dsu, unordered_map<string, int>& emailToID) {
        int n = uniqueEmails.size();
        vector<vector<string>> ans(n);
        for(auto& email: uniqueEmails) {
            int u = emailToID[email];
            int pu = dsu.find(u);
            ans[pu].push_back(email);
        }
        return ans;
    }

    DSU createDSU(int& n, vector<vector<string>>& accounts, unordered_map<string, int>& emailToID) {
        DSU dsu(n);
        for(auto& account: accounts) {
            int u = emailToID[account[1]];
            for(int i=2; i<account.size(); i++) {
                int v = emailToID[account[i]];
                dsu.unionByRank(u, v);
            }
        }
        return dsu;
    }

    unordered_map<string, int> getEmailToID(vector<vector<string>>& accounts) {
        unordered_map<string, int> ans;
        int id = 0;
        for (auto& account : accounts) {
            for (int i = 1; i < account.size(); i++) {
                if (ans.find(account[i]) == ans.end()) {
                    ans[account[i]] = id;
                    id++;
                }
            }
        }
        return ans;
    }

    unordered_map<string, string> getEmailToName(vector<vector<string>>& accounts) {
        unordered_map<string, string> ans;
        for (auto& account : accounts) {
            string name = account[0];
            for (int i = 1; i < account.size(); i++) {
                ans[account[i]] = name;
            }
        }
        return ans;
    }

    unordered_set<string> getUniqueEmails(vector<vector<string>>& accounts) {
        unordered_set<string> ans;
        for (auto& account : accounts) {
            for (int i = 1; i < account.size(); i++) {
                ans.insert(account[i]);
            }
        }
        return ans;
    }
};