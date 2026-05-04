class Solution {
public:
    bool checkValidString(string s) {
        std::stack<int> ch;
        std::stack<int> ast;

        for(int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')
                ch.push(i);
            else if (s[i] == '*')
                ast.push(i);
            else {
                if (!ch.empty())
                    ch.pop();
                else if (!ast.empty())
                    ast.pop();
                else
                    return false;
            }
        }

        while (!ch.empty() && !ast.empty()) {
            if (ast.top() < ch.top())
                return false;
            ch.pop();
            ast.pop();
        }

        return ch.empty();
    }
};
