class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int max = prices[0];
        int min = prices[0];
        int profit = 0;

        while (i < prices.size() - 1) {
            while (i < prices.size() - 1 && prices[i] >= prices[i+1]) i++;
            min = prices[i];
            while (i < prices.size() - 1 && prices[i] <= prices[i+1]) i++;
            max = prices[i];

            profit += (max - min);
        }

        return profit;
    }
};
