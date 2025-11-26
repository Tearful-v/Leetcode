class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(); // кол-во строк
        int n = grid[0].size(); // кол-во столбцов
        vector<vector<int>> dp(m, vector<int>(n));
        for (int j = 0; j < n; j++)
            dp[0][j] = grid[0][j];
        for (int i = 1; i < m; i++)
            for (int j = 0; j < n; j++){
                int val = 10000;
                for (int curj = 0; curj < n; curj++){
                    int move = dp[i - 1][curj] + moveCost[grid[i - 1][curj]][j];
                    val = min(val, move);
                }
                dp[i][j] = grid[i][j] + val;
            }
        int val = 10000;
        for (int j = 0; j < n; j++)
            val = min(val, dp[m - 1][j]);
        return val;
    }
};