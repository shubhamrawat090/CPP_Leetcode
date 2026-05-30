class Solution {
public:
    string replaceWords(vector<string>& dictionary,
                        string sentence) {

        unordered_set<string> roots(
            dictionary.begin(),
            dictionary.end()
        );

        stringstream ss(sentence);

        string word;

        string ans = "";

        while (ss >> word) {

            string prefix = "";

            bool replaced = false;

            for (char ch : word) {

                prefix.push_back(ch);

                if (roots.count(prefix)) {
                    ans += prefix;
                    replaced = true;
                    break;
                }
            }

            if (!replaced) {
                ans += word;
            }

            ans += " ";
        }

        ans.pop_back();

        return ans;
    }
};