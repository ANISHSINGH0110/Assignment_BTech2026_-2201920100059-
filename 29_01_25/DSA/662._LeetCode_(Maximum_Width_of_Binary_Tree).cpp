
/*
Approach

The problem requires calculating the maximum width of any level in a binary tree. 
The width of a level is defined as the number of nodes between the leftmost and rightmost non-null nodes of the level, including nullptr positions in between.

Key Concepts:
Breadth-First Search (BFS):
The solution employs BFS using a queue to traverse the binary tree level by level.

Indexing Nodes:
Nodes are assigned indices like in a complete binary tree representation to maintain their relative positions.

The left child of a node at index i is 2 * i.
The right child of a node at index i is 2 * i + 1.
This indexing helps compute the width efficiently.

Time Complexity: O(N) — Every node is processed once.


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
    int widthOfBinaryTree(TreeNode* root) {
       unsigned long long maxWidth = 0;
       if(!root)
        return maxWidth;
        queue<pair<TreeNode* , unsigned long long >> q;
        q.push({root,1});
        while(!q.empty())
        {
            unsigned long long size = q.size();
            unsigned long long leftMostIndex = q.front().second;
            unsigned long long rightMostIndex = q.back().second;
            unsigned long long currLevelWidth = rightMostIndex-leftMostIndex+1;
            maxWidth = max(maxWidth,currLevelWidth);
            //traverse over all node of curr level
            for(unsigned long long i=0;i<size;i++)
            {
                auto front = q.front();
                q.pop();;
                auto node = front.first;
                auto index = front.second;
                //process it's child and assign them the index
                if(node->left)
                  q.push({node->left,2*index});
                if(node->right)
                  q.push({node->right,2*index+1});  
            }
        }
        return maxWidth;
    }
};