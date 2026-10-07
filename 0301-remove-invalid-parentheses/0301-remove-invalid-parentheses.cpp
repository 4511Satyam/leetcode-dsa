class Solution {
public:
    set<string> ans;

    void dfs(string &s, int i, int lrem, int rrem,
             int open, string cur) {

        if (i == s.size()) {
            if (lrem == 0 && rrem == 0 && open == 0)
                ans.insert(cur);
            return;
        }

        // Remove current character
        if (s[i] == '(' && lrem > 0)
            dfs(s, i + 1, lrem - 1, rrem, open, cur);

        if (s[i] == ')' && rrem > 0)
            dfs(s, i + 1, lrem, rrem - 1, open, cur);

        // Keep current character
        if (s[i] == '(') {
            dfs(s, i + 1, lrem, rrem, open + 1, cur + '(');
        }
        else if (s[i] == ')') {
            if (open > 0)
                dfs(s, i + 1, lrem, rrem, open - 1, cur + ')');
        }
        else {
            dfs(s, i + 1, lrem, rrem, open, cur + s[i]);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int lrem = 0, rrem = 0;

        for (char c : s) {
            if (c == '(')
                lrem++;
            else if (c == ')') {
                if (lrem > 0)
                    lrem--;
                else
                    rrem++;
            }
        }

        dfs(s, 0, lrem, rrem, 0, "");

        return vector<string>(ans.begin(), ans.end());
    }
};