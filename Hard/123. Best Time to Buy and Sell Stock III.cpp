class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = -prices[0];
        int sell1 = 0;
        int buy2 = -prices[0];
        int sell2 = 0;

        for (int i = 0; i < prices.size(); ++i) {
            buy1 = std::max(buy1, -prices[i]);
            sell1 = std::max(sell1, buy1 + prices[i]);
            buy2 = std::max(buy2, sell1 - prices[i]);
            sell2 = std::max(sell2, buy2 + prices[i]);
        }

        return sell2;
    }
};
