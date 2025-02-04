/*
This solution efficiently finds the maximum sum of any ascending contiguous subarray in a vector of integers.
*/
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxSum = 0; 
        int currentSum = nums[0];  // Initialize with the first element

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                currentSum += nums[i];  // Continue the ascending sequence
            } else {
                maxSum = max(maxSum, currentSum);  // Update maxSum if necessary
                currentSum = nums[i];  // Reset the current sum for the new subarray
            }
        }

        // Check the last subarray sum
        maxSum = max(maxSum, currentSum);

        return maxSum;
    }
};
