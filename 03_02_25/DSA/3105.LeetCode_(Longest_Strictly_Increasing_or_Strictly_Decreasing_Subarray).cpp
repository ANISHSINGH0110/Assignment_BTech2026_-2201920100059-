/*
int n: Stores the size of the input array nums.
int longest: Keeps track of the length of the longest monotonic subarray.
int sInc = 1, sDec = 1: Two variables initialized to 1 to track the lengths of increasing and decreasing sequences, respectively.
Use a for loop starting from index 1 up to n - 1
Increasing Subarray Check:
If the current element nums[i] is greater than the previous element nums[i - 1], increment the sInc counter. If not, reset sInc to 1.
Decreasing Subarray Check:
If the current element nums[i] is smaller than the previous element nums[i - 1], increment the sDec counter. Otherwise, reset sDec to 1.
At each step, compute the maximum of the current longest, sInc, and sDec.
After iterating through the array, return the longest length as the answer.

Time Complexity: O(n)
The algorithm traverses the array once, making it linear time.
*/
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int longest = 1;
        int sInc = 1;
        int sDec = 1;
        for(int i = 1;i<n;i++){
            if(nums[i] > nums[i-1])
               sInc++;
            else  
               sInc = 1;
            if(nums[i] < nums[i-1])
                sDec++;
            else
                sDec = 1;
            longest = max({longest,sInc,sDec});

        }
        return longest;
    }
};