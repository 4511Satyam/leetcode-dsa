class Solution {
public:
    int minInsertions(string s) {
        int ans = 0, open = 0;

        for (char c : s) {
            if (c == '(') {
                if (open > 0) {
                    ans += open % 2;
                    open -= open % 2;
                }
                open += 2;
            } else {
                open--;
                if (open < 0) {
                    ans++;
                    open = 1;
                }
            }
        }

        return ans + open;
    }
};