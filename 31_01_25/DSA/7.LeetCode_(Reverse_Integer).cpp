/*
This solution reverses the digits of a given 32-bit signed integer (x) while handling edge cases such as overflow.

int ans = 0: Variable to store the reversed integer.

Continue while x != 0 to extract and process each digit.
In each iteration:
Extract the last digit using x % 10.
Remove the last digit by updating x = x / 10.

Before updating ans, check whether multiplying ans by 10 will cause an overflow or underflow:

If ans > INT_MAX / 10, adding any digit will exceed INT_MAX.
If ans < INT_MIN / 10, adding any digit will go below INT_MIN.
Additionally, check edge cases when ans == INT_MAX / 10 or ans == INT_MIN / 10.
In these cases, if the digit to be added exceeds 7 for positive numbers or is less than -8 for negative numbers, return 0.

If no overflow or underflow is detected, update ans:
 ans=(ans×10)+digit
*/

class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        while(x != 0)
        {
            int digit = x%10;
            if((ans > INT_MAX/10)||(ans < INT_MIN/10))
            {
                return 0;
            }
            ans = (ans*10) + digit;
            x = x/10;
        }
        return ans;
    }
};