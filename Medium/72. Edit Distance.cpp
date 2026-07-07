//перенос сверху - удаление из длинно гослова
//перенос слева - вствака из короткого
//диагональный перенос - либо первые символы совпали / либо замена -> +cost(1/0)

class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() < word2.size())
            return minDistance(word2, word1);
        int size1 = word2.size() + 1;
        int size2 = word1.size() + 1;

        int dp[size1][size2];
        for (int i = 0; i < size1; ++i)
            dp[i][0] = i;
        for (int j = 0; j < size2; ++j)
            dp[0][j] = j;

        for (int i = 1; i < size1; ++i) {
            for (int j = 1; j < size2; ++j) {
                int cost = (word1[j - 1] == word2[i - 1]) ? 0 : 1;
                dp[i][j] = std::min (
                    dp[i][j-1] + 1,
                    std:: min (dp[i-1][j] + 1, dp[i-1][j-1] + cost)
                );
            }
        }

        return dp[size1-1][size2-1];
    }
};
