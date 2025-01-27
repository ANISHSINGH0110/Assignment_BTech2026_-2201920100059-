/*
The given problem is to remove k digits from the string num to obtain the smallest possible number. 
The solution follows a greedy algorithm approach using a stack to ensure that digits are removed optimally to achieve the smallest lexicographical order.

Key Observations:
A digit should be removed if it is greater than the next digit, ensuring a smaller number.
If after iterating through the number, k digits are not removed, the last k digits should be removed.
Handle leading zeros to ensure no unnecessary leading zeros are present in the final result.
If the resulting string is empty, return "0".

Use a stack to keep track of digits to construct the smallest number.
Iterate through each digit in num and make decisions to push or pop elements.

Traverse through each digit in num:
If k > 0 and the current digit is smaller than the top of the stack, remove the top element (pop) to make the number smaller.
Decrement k after popping.
Push the current digit onto the stack.

After the loop, if k > 0, remove additional digits from the top of the stack.

Pop elements from the stack and store them in a string.
Reverse the string since the stack holds digits in reverse order.

Trim trailing zeros (after reversing).
If the resultant string is empty, return "0".

time complexity: O(n).
*/



class Solution {
public:
    string removeKdigits(string num, int k) {
      string ans;
      stack<char>st;
      
      for(auto digit:num)
      {
        if(k > 0)
        {
            while(!st.empty() && st.top() > digit)
            {
                st.pop();
                k--;
                if(k == 0)
                  break;

            }
        }
        st.push(digit);
      } 
      
      if(k > 0)
      {
        while(!st.empty() && k)
        {
            st.pop();
            k--;
        }
      }

      while(!st.empty())
      {
        ans.push_back(st.top());
        st.pop();
      }
      //removing leading zeros
      while(ans.size() > 0 && ans.back() == '0')
         ans.pop_back();
      //get real ans
      reverse(ans.begin(),ans.end());
      return ans == "" ? "0" : ans;   


    }
};