/*
The task is to find the maximum path sum in a binary tree. A path is defined as any sequence of nodes from some starting node to 
any node in the tree along parent-child connections. The path does not need to pass through the root.

1. Brute Force Method (Commented Out)
This method explored all root-to-leaf paths and tracked the sum for the longest path.

Time complexity: O(n^2 ) due to redundant subtree calls.

2. Optimized Recursive Method (Implemented)
This approach uses a recursive helper function maxPathSumUtil() to efficiently calculate the maximum path sum by leveraging a post-order traversal of the tree.
*/
class Solution {
    public:
        void solve(TreeNode* root,int sum,int &maxSum,int len,int &maxLen)
        {
            if (root == nullptr) {
                return;
            }
    
            sum += root->val;
    
            // Check if it's a leaf node
            if (root->left == nullptr && root->right == nullptr) {
                if (len + 1 > maxLen) {
                    maxLen = len + 1;
                    maxSum = sum;
                } else if (len + 1 == maxLen) {
                    if (sum > maxSum) {
                        maxSum = sum;
                    }
                }
            } else {
                // Continue to explore the left and right subtrees
                solve(root->left, sum, maxSum, len + 1, maxLen);
                solve(root->right, sum, maxSum, len + 1, maxLen);
            }
        }
    
         int maxPathSumUtil(TreeNode* root, int &maxSum) {
            if (root == nullptr) {
                return 0;
            }
    
            // Recursively get the maximum path sum for the left and right subtrees
            int leftSum = max(0, maxPathSumUtil(root->left, maxSum));  // Only consider positive sums
            int rightSum = max(0, maxPathSumUtil(root->right, maxSum)); // Only consider positive sums
    
            // Update maxSum if the path through the current node is greater
            int currentSum = root->val + leftSum + rightSum;
            maxSum = max(maxSum, currentSum);
    
            // Return the maximum path sum including the current node and one of its subtrees
            return root->val + max(leftSum, rightSum);
        }
        int maxPathSum(TreeNode* root) {
            // int len = 0;
            // int maxLen = 0;
            // int sum = 0;
            // int maxSum = INT_MIN;
            // solve(root,sum,maxSum,len,maxLen);
            // return maxSum;
    
    
            int maxSum = INT_MIN;
            maxPathSumUtil(root, maxSum);
            return maxSum;
        }
    };