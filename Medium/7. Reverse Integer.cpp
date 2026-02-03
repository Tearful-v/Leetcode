class Solution {
public:
    int reverse(int x) {
        int answer = 0;
        bool sign;
        if(x < 0)
            sign = false;
        else
            sign = true;
        while(x != 0){
            int digit = x % 10;
            x /= 10;
            if((answer > INT_MAX/10) || (answer < INT_MIN/10))
                return 0;
            answer = answer * 10 + digit;
        }
        answer = abs(answer);
        if(!sign)
            answer *= -1;
        return answer;
    }
};