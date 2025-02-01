/*
The problem requires determining whether the given integer array nums is "special." 
An array is considered "special" if adjacent elements in the array have alternating parities (i.e., even-odd or odd-even).

Get the size of the array, n = nums.size().
If the array has n = 0 or n = 1, it is trivially special because no adjacent elements violate the rule.
Traverse the array from index 1 to n - 1 using a for loop.
For each index i, check whether the parity of the current element nums[i] is the same as the previous element nums[i - 1].
This can be efficiently checked using the expression nums[i] % 2 == nums[i - 1] % 2.
If this condition is true, return false as the array violates the "special" rule.
If no violations are found during traversal, return true, indicating that the array is special.

Time Complexity: O(n) — Linear time complexity since we traverse the array once.
*/

class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]%2==nums[i-1]%2){
                return false;
            }
        }
        return true;
    }
};