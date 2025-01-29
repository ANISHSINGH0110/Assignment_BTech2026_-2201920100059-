/*
Approach

The problem requires placing the minimum number of cameras in a binary tree to monitor all nodes. 
Each camera placed at a node can monitor its parent, itself, and its immediate children.

Key Concepts Used:
Tree Traversal: The solution uses a post-order traversal (left, right, root) to handle subtrees before making decisions at the current node.
Greedy Approach: Cameras are placed only where absolutely necessary to cover uncovered nodes or subtrees efficiently.
State Management: Each node can have one of three states:
0: Not covered
1: Covered but no camera
2: Covered and has a camera

solve(TreeNode* root, int &camera)
Base Case:
If the current node is nullptr, it is considered covered (return 1).

Recursive Calls:
Recursively check the left and right child nodes

Decision Making:

If either child is not covered (left == 0 || right == 0), place a camera at the current node (camera++).
Return 2 to indicate that this node has a camera.
If either child has a camera (left == 2 || right == 2), the current node is already covered.
Return 1.
If both children are covered but have no cameras (left == 1 && right == 1), the current node is uncovered.
Return 0.

minCameraCover(TreeNode* root)
Initializes camera to count the total number of cameras.
Calls solve(root, camera).
If the root node itself is uncovered (rootstate == 0), place one more camera.
Returns the total number of cameras.

Time Complexity: O(N) — Each node is visited once.
*/




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root,int &camera)
    {
        if(!root)//all nodes are assumed to be covered
          return 1;
        int left = solve(root->left,camera);
        int right = solve(root->right,camera);
        if(left == 0 || right == 0)//either node are connected
        {
            camera++;
            return 2;//my cam is installed
        }
        if(left == 2 || right == 2)//i'm covered by my child
        {
            return 1;
        }
        return 0;//i'm not covered

    }
    int minCameraCover(TreeNode* root) {
       int camera = 0;
       int rootstate = solve(root,camera);
       if(rootstate == 0)
         camera++;
       return camera;   
    }
};