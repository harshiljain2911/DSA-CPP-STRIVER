class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.length();
        long num = 0;  // long for overflow safety
        int sign = 1;

        // 1. Skip spaces
        while(i < n && s[i] == ' ') i++;

        // 2. Handle sign
        if(i < n && (s[i] == '+' || s[i] == '-')) {
            if(s[i] == '-') sign = -1;
            i++;
        }

        // 3. Process digits
        while(i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // 4. Check overflow
            if(num > (INT_MAX - digit) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            num = num * 10 + digit;
            i++;
        }

        return num * sign;
    }
};
