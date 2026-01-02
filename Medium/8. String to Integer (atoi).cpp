class Solution {
public:
    int myAtoi(string s) {
        int answer = 0;
        int sign = 1;
        int i = 0;
        while(i < s.size() && s[i] == ' '){
            i++;
        }
        if(i < s.size() && (s[i] == '-' || s[i] == '+')){
            if(s[i] == '-')
                sign = -1;
            i++;
        }
        while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
            if (answer > (INT_MAX - (s[i] - '0')) / 10) {
            return sign == 1 ? INT_MAX : INT_MIN;
            }
            answer = answer * 10 + (s[i] - '0');
            i++;
        }
        answer = answer * sign;
        return answer;
    }
};