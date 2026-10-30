class Solution {
public:
    std::vector<std::string> answers;
    size_t max_len = 0;

    void dfs(int st_i, int st_j, std::string tmp,
        std::unordered_set<std::string_view>& word,
        vector<vector<char>>& board,
        const std::unordered_set<std::string>& prefixes) {

        if (!prefixes.contains(tmp)) {
            return;
        }

        if(word.empty()) {
            return;
        }

        auto it = word.find(tmp);

        if (it != word.end()) {
            answers.push_back(tmp);
            word.erase(it);
        }

        if (tmp.size() >= max_len || word.empty()) {
            return;
        }
        const int n = board.size();
        const int m = board[0].size();

        char original = board[st_i][st_j];
        board[st_i][st_j] = '#';

        if (st_i + 1 < n && board[st_i + 1][st_j] != '#') {
            dfs(st_i + 1, st_j,
                tmp + board[st_i + 1][st_j], word, board, prefixes);
        }

        if (st_i - 1 >= 0 && board[st_i - 1][st_j] != '#') {
            dfs(st_i - 1, st_j,
                tmp + board[st_i - 1][st_j], word, board, prefixes);
        }

        if (st_j + 1 < m && board[st_i][st_j + 1] != '#') {
            dfs(st_i, st_j + 1,
                tmp + board[st_i][st_j + 1], word, board, prefixes);
        }

        if (st_j - 1 >= 0 && board[st_i][st_j - 1] != '#') {
            dfs(st_i, st_j - 1,
                tmp + board[st_i][st_j - 1], word, board, prefixes);
        }

        board[st_i][st_j] = original;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        std::unordered_set<std::string_view> word(words.begin(), words.end());
        for (const auto& w : words) {
            max_len = std::max(max_len, w.size());
        }

        std::unordered_set<std::string> prefixes;

        for (const auto& w : words) {
            std::string prefix;

            for (char c : w) {
                prefix += c;
                prefixes.insert(prefix);
            }
        }

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(i, j, std::string(1, board[i][j]), word, board, prefixes);
                if(word.empty()) {
                    break;
                }
            }
        }
        std::ranges::sort(answers);
        auto [first, last] = std::ranges::unique(answers);
        answers.erase(first, last);

        return answers;
    }
};
