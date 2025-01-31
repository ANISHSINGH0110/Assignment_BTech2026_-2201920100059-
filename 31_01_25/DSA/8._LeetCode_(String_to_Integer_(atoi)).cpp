/*
This solution efficiently converts a given string to a 32-bit signed integer 
while handling edge cases like whitespaces, sign symbols, overflow, and invalid characters. Here's a step-by-step explanation:
Initialize:
num = 0: This will store the resulting integer.
i = 0: Index pointer for traversing the input string.
sign = 1: Variable to handle the sign of the integer (+1 for positive, -1 for negative).

Loop through the string while s[i] == ' '.
Increment i to move past any spaces until a valid character is encountered.
Check if the current character is either '+' or '-'.
Set sign = -1 if the sign is negative ('-'); otherwise, keep it 1 for positive.
Increment i to move past the sign symbol.
Traverse the characters until a non-digit character is encountered.

For each digit, update the integer num using:
num=num×10+(s[i]− ′0 ′)

Check for overflow or underflow:

If num > INT_MAX / 10 or num == INT_MAX / 10 && s[i] > '7', return appropriate bounds:
INT_MAX if the sign is positive.
INT_MIN if the sign is negative.
Return num * sign to account for both positive and negative integers.

Edge Cases Covered
Leading spaces: Skipped.
Sign symbols: Properly handled.
Non-digit characters: Parsing stops when a non-digit is encountered.
Overflow/Underflow: Returns INT_MAX or INT_MIN as per the constraints.
Invalid input: Returns 0 if no valid integer is parsed.

Time Complexity: O(n), where n is the length of the input string (s).


*/


class Solution {
public:
    int myAtoi(string s) {
    // int i = 0;
    // int sign = 1;
    // long long result = 0;
    
    // // Skip leading whitespaces
    // while (i < s.size() && s[i] == ' ') {
    //     ++i;
    // }
    
    // // Check for sign
    // if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
    //     sign = (s[i++] == '-') ? -1 : 1;
    // }
    
    // // Convert digits
    // while (i < s.size() && isdigit(s[i])) {
    //     result = result * 10 + (s[i++] - '0');
        
    //     // Check for overflow/underflow
    //     if (result * sign > numeric_limits<int>::max()) {
    //         return numeric_limits<int>::max();
    //     } else if (result * sign < numeric_limits<int>::min()) {
    //         return numeric_limits<int>::min();
    //     }
    // }
    
    // return result * sign;


    // int integer = atoi(s.c_str());
    // return integer;


    int num =0,i=0,sign =1;
    while(s[i] == ' ')
      i++;
    while(i<s.size() && (s[i] == '-' || s[i] == '+'))
    {
        sign = s[i] == '+'? 1 : -1;
        ++i;
    }  
    while(i<s.size() && isdigit(s[i]))
    {
        if(num > INT_MAX/10 || (num == INT_MAX/10 && s[i] >'7'))
          return sign == -1 ? INT_MIN:INT_MAX;
        num = num*10+(s[i] - '0');
        ++i;  
    }
    return num*sign;
    }
};