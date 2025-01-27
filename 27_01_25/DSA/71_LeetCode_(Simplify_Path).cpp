/*
The given problem is to simplify an absolute Unix-style file path. 
The goal is to resolve . (current directory), .. (parent directory), and multiple slashes (/) to produce a simplified canonical path.

We need to process the string path and construct a simplified version following these rules:

"." refers to the current directory, so it should be ignored.
".." refers to the parent directory, meaning we should remove the last valid directory if it exists.
Consecutive slashes // should be treated as a single /.

Use a stack to keep track of directory names.
Push valid directory names onto the stack.
Pop the stack for .. to remove the last valid directory.

Use a stack<string> to store directory names.
Use index variables to iterate through the path string.

Traverse the path string and extract substrings between slashes (/).
If the substring is "." (current directory) or empty, ignore it.
If the substring is ".." (parent directory), pop the top directory from the stack (if not empty).
Otherwise, push valid directory names onto the stack.

Use a helper function buildAns to reconstruct the simplified path from the stack.
If the stack is empty, return "/".
Otherwise, concatenate all directory names to form the final result.

Time Complexity: O(n)

*/


class Solution {
public:
    void buildAns(stack<string>&s,string &ans)
    {
        if(s.empty())
          return;
        string minPath = s.top();
        s.pop();
        buildAns(s,ans);
        ans += minPath;  
    }
    string simplifyPath(string path) {
        stack<string>s;
        int i = 0 ;
        while(i < path.size())
        {
            int start = i;
            int end = i+1;
            while(end < path.size() && path[end] != '/')
              ++end;
            string minPath = path.substr(start,end-start);
            i = end;
            if(minPath == "/" || minPath == "/.")
              continue;
            if(minPath != "/..")
              s.push(minPath);
            else if(!s.empty())
              s.pop();      
        }
        string ans = s.empty() ? "/" : "";
        buildAns(s,ans);
        return ans;

    }
};