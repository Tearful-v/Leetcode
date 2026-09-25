class Solution {
public:
    int n = 0;
    int m = 0;

    int dfs(vector<vector<int>>& dp,
            const vector<vector<int>>& matrix,
            int i, int j) {

        if (dp[i][j] != 0) {
            return dp[i][j];
        }

        int left = 0;
        int right = 0;
        int down = 0;
        int up = 0;

        if (i - 1 >= 0 && matrix[i - 1][j] > matrix[i][j]) {
            up = dfs(dp, matrix, i - 1, j);
        }
        if (i + 1 < n && matrix[i + 1][j] > matrix[i][j]) {
            down = dfs(dp, matrix, i + 1, j);
        }
        if (j - 1 >= 0 && matrix[i][j - 1] > matrix[i][j]) {
            left = dfs(dp, matrix, i, j - 1);
        }
        if (j + 1 < m && matrix[i][j + 1] > matrix[i][j]) {
            right = dfs(dp, matrix, i, j + 1);
        }

        dp[i][j] = 1 + std::max(std::max(left, right), std::max(up, down));
        return dp[i][j];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int result = 0;
        n = matrix.size();
        m = matrix[0].size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                result = std::max(result, dfs(dp, matrix, i, j));
            }
        }
        return result;
    }
};
