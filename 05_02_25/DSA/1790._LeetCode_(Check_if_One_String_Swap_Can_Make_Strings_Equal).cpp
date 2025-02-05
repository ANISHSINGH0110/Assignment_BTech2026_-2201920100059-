/*
Identify the number of positions where s1[i] != s2[i].
If there are no mismatches, or exactly two mismatches where swapping resolves equality, return true.
Return false otherwise.

If s1 == s2, return true.
Use diffIndices to store positions where the characters of s1 and s2 differ.
Return true if exactly two differences can be resolved by a swap.

Time Complexity: O(N) 
*/
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        // sort(s1.begin(),s1.end());
        // sort(s2.begin(),s2.end());
        // if(s1 == s2)
        //   return true;
        // else
        //   return false;  


        if (s1 == s2) return true;

        vector<int> diffIndices;

        // Find positions where characters differ
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                diffIndices.push_back(i);
            }
        }

        // Check if there's exactly two differences that can be swapped
        return diffIndices.size() == 2 &&
               s1[diffIndices[0]] == s2[diffIndices[1]] &&
               s1[diffIndices[1]] == s2[diffIndices[0]];
    }
};