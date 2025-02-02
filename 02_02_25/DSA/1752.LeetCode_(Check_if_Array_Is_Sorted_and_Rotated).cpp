/*
The problem is to determine whether the given array nums can be rotated to become a non-decreasing sorted array. 

We iterate through the array from i = 1 to n - 1 and count how many times the condition nums[i - 1] > nums[i] is true.
This condition indicates a "breakpoint" where the sequence is not non-decreasing.
After traversing the entire list, we also need to check whether nums[n - 1] > nums[0].
This check handles the wrap-around part, as nums is circular. If the last element is greater than the first element, it indicates a potential rotation problem.
The key observation is that the array is sorted and rotated if there is at most one breakpoint in the sequence.
Therefore, we return true if count <= 1. Otherwise, false.


Time Complexity: O(n) — Single pass through the array
*/
class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]>nums[i])
            {
                count++;
            }
        }
        if(nums[n-1]>nums[0])
           count++;
        return count <=1;   
    }
};