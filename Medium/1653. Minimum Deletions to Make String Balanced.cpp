class Solution {
public:
    int minimumDeletions(string s) {
        int answer = 0;
        int b = 0;
        int a = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'b')
                b++;
            else
                answer = std::min(answer+1, b);
        }
        return answer;
    }
};
