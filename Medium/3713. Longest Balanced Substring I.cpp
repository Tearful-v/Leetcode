class Solution {
public:
    int longestBalanced(string s) {
        std::unordered_map<char, int> mp;
        int n = s.size();
        int answer = 0;
        for(int i = 0; i < n; i++){
            mp = {};
            for(int j = i; j < n; j++){
                mp[s[j]]++;
                bool flag = true;
                int cnt = mp[s[j]];
                for(auto& tmp : mp){
                    if(tmp.second != cnt){
                        flag = false;
                        break;
                    }
                }
                if(flag)
                    answer = std::max(answer, j-i+1);
            }
        }
        return answer;
    }
};
