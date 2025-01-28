//Approach
/*

The problem can be solved using a stack-based approach to validate if the string contains only valid sequences of "abc" as a unit. 
Each time the sequence "abc" appears, it is effectively removed by managing the characters on the stack.

If the first character of the string s[0] != 'a', return false.
This is because a valid sequence must always begin with the letter a.

Use a stack (st) to maintain characters that are part of potential valid sequences.

Iterate Through the String:

Case 1: If the current character is 'a', push it onto the stack.
Case 2: If the current character is 'b':
Check if the stack is not empty and the top element is 'a'.
If true, push 'b' onto the stack. Otherwise, return false.
Case 3: If the current character is 'c':
Check if the stack is not empty and the top element is 'b'.
If true, pop the 'b'.
After popping 'b', check again if the stack is not empty and the top element is 'a'.
If true, pop the 'a'.
If either check fails, return false.

Final Check:

Return true only if the stack is empty after processing the entire string.
An empty stack implies all "abc" sequences have been correctly validated and removed.

Time Complexity: O(n)
*/







class Solution {
public:
    bool isValid(string s) {
       if(s[0] != 'a')
         return false;
       stack<char>st;
       for(char ch : s)
       {
          if(ch == 'a')
             st.push(ch);
          else if(ch == 'b')
          {
             if(!st.empty() && st.top() == 'a')
                 st.push('b');
             else
               return false;

          }   
          else
          {
            if(!st.empty() && st.top() == 'b')
            {
                st.pop();
                if(!st.empty() && st.top() == 'a')
                  st.pop();
                else
                  return false;  
            }
            else
               return false;
          }

       }
       return st.empty();  
    }
};