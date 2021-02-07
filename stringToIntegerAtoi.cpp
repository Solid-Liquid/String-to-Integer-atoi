

class Solution {
public:
    
    int myAtoi(string s) {
        int idx=0, num=0, neg=1, tmp;
        
        while(idx < s.length() && s[idx] == ' ')    //step 1
            ++idx;
        
        if(idx < s.length() && (s[idx] == '-' || s[idx] == '+'))    //step 2
            if(s[idx++] == '-')
                neg = -1;

        while(idx < s.length() && s[idx] > 47 && s[idx] < 58){          //step 3
            tmp = s[idx] - 48;                                          //step 4
            if (num > INT_MAX/10 || (num == INT_MAX/10 && tmp > 7))     //step 5
                return neg==1 ? INT_MAX : INT_MIN;
            num = 10 * num + tmp;
            ++idx;
        }
        
        return num*neg;     //step 6
    } 
};

//Notes:
//In step 3, the ascii range for chars 0-9 is 48 - 57 inclusive
//In step 4, simply subtract the ascii value for '0' to convert to int
//In step 5, we check for integer overflow/underflow.
//We are about to multipy by 10, so we check num against INT_MAX/10
//Otherwise, if num equals INT_MAX/10, we check if the new digit will go above the last
//digit in INT_MAX (which is 7).
//This check for INT_MAX also covers our INT_MIN case. If the final num is negative and is
//equivalent to INT_MIN, which has last digit 8, then the correct answer will come out regardless.