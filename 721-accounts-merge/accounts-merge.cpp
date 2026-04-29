class Solution {
    struct DSU {
        vector<int> parent;
        vector<int> rank;

        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for(int i=0; i<n; i++) {
                parent[i] = i;
            }
        }

        int find(int u) {
            if(parent[u] == u) return parent[u];
            return parent[u] = find(parent[u]);
        }

        void unionByRank(int u, int v) {
            int pu = find(u), pv = find(v);

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
        // APPROACH: 
        // We need email -> unique ID/num map for DSU(intuitive with numbers than strings)
        // We need email -> name map --> O(1) access of name for an email
        // Group same emails together
        // WHAT IS A GROUP? [a, b, c, d]. a--b, a--c, a--d. This is a group, everything in a same array is a same group
        // If a new group [b, e]. b--e. But, b is under a --> b, e are under a as well. Now we have a new group, [a,b,c,d,e]
        // At the end after grouping, get same group emails array AND SORT THEM(asked in question)
        // you have [a,b,c,d,e]. Get the name for 'a' from the email->name map and push [name, a,b,c,d,e] in answer
        unordered_map<string, int> emailToNum = getEmailToNum(accounts);
        unordered_map<string, string> emailToName = getEmailToName(accounts);
        int n = emailToNum.size(); // no. of nodes
        DSU dsu = buildEmailsDSU(accounts, n, emailToNum);
        vector<vector<string>> sameGroupEmails = getSameEmailGroups(dsu, n, emailToNum);
        return buildEmailWithNames(sameGroupEmails, emailToName);
    }

private:
    unordered_map<string, int> getEmailToNum(vector<vector<string>>& accounts) {
        int num = 0;
        unordered_map<string, int> emailToNum;
        for(auto& account: accounts) {
            for(int i=1; i<account.size(); i++) {
                string email = account[i];
                if(emailToNum.find(email) == emailToNum.end()) {
                    emailToNum[email] = num;
                    num++;
                }
            }
        }
        return emailToNum;
    }

    unordered_map<string, string> getEmailToName(vector<vector<string>>& accounts) {
        unordered_map<string, string> emailToName;
        for(auto& account: accounts) {
            string name = account[0];
            for(int i=1; i<account.size(); i++) {
                emailToName[account[i]] = name;
            }
        }
        return emailToName;
    }

    DSU buildEmailsDSU(vector<vector<string>>& accounts, int n, unordered_map<string, int>& emailToNum) {
        DSU dsu(n);
        for(auto& account: accounts) {
            // [a, b, c]: a--b, a--c
            string firstEmail = account[1];
            int u = emailToNum[firstEmail];
            for(int i=2; i<account.size(); i++) {
                string email = account[i];
                int v = emailToNum[email];
                dsu.unionByRank(u, v);
            }
        }
        return dsu;
    }

    vector<vector<string>> getSameEmailGroups(DSU& dsu, int n, unordered_map<string, int>& emailToNum) {
        vector<vector<string>> sameEmailGroups(n); // index i is the uniqueNum of each email in emailToNum
        // OBJECTIVE: sameEmailGroups[parent_u] = {all emails whose parent is parent_u}
        // NOTE: There is a change certain groups are empty because emails can merge
        for(auto& it: emailToNum) {
            string email = it.first;
            int u = it.second;
            int pu = dsu.find(u);
            sameEmailGroups[pu].push_back(email);
        }
        return sameEmailGroups;
    }

    vector<vector<string>> buildEmailWithNames(vector<vector<string>>& sameGroupEmails, unordered_map<string, string>& emailToName) {
        vector<vector<string>> emailWithNames;
        for(auto& groupEmails: sameGroupEmails) {
            if(groupEmails.empty()) continue; // skip empty groups
            sort(groupEmails.begin(), groupEmails.end()); // Question demands sorted
            string firstEmail = groupEmails[0];
            string name = emailToName[firstEmail];
            vector<string> emailGroupWithName = {name, firstEmail};
            for(int i=1; i<groupEmails.size(); i++) {
                emailGroupWithName.push_back(groupEmails[i]);
            }
            emailWithNames.push_back(emailGroupWithName);
        }
        return emailWithNames;
    }
};