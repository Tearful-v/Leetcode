class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> res;
        int open = 0;
        int close = 0;
        dfs(res, "", open, close, n);
        return res;
    }

    void dfs(std::vector<std::string> &res, std::string tmp, int open, int close, int n) {
        if (open == close && open + close == 2*n) {
            res.push_back(tmp);
            return;
        }

        if (open < n) dfs(res, tmp+'(', open+1, close, n);
        if (close < open) dfs(res, tmp+')', open, close+1, n);
    }
};
