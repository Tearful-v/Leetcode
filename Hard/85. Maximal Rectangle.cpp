class Solution {
public:

    int largestRectangleArea(vector<int>&& heights) {
        int answ = 0;
        std::stack<int> st;

        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();

                int width = st.empty() ? i : i - st.top() - 1;
                answ = std::max(answ, h * width);
            }

            st.push(i);
        }

        int n = heights.size();
        while (!st.empty()) {
            int h = heights[st.top()];
            st.pop();

            int width = st.empty() ? n : n - st.top() - 1;
            answ = std::max(answ, h * width);
        }

        return answ;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }

        std::vector<std::vector<int>> dp(matrix.size(),
            std::vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); ++i) {
            dp[i][0] = matrix[i][0] - '0';
        }

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 1; j < matrix[0].size(); ++j) {
                dp[i][j] = (matrix[i][j] == '0') ? 0 : ((matrix[i][j] - '0') + (dp[i][j - 1]));
            }
        }

        int answer = 0;

        for (int j = 0; j < matrix[0].size(); ++j) {
            std::vector<int> tmp;
            for (int i = 0; i < matrix.size(); ++i) {
                tmp.push_back(dp[i][j]);
            }
            answer = std::max(answer, largestRectangleArea(std::move(tmp)));
        }

        return answer;
    }
};
