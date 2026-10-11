class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
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
};
