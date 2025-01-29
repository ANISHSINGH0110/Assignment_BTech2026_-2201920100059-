
/*
Approach

The task is to find all nodes in a binary tree that are exactly distance K from a given target node.

Key Concepts:
Tree Traversal:
Use DFS to map parent nodes and BFS to explore nodes at distance K.

Parent Mapping:
Since binary trees do not directly support backward traversal, maintain a parent map to access parent nodes of any node during traversal.

Breadth-First Search (BFS):
BFS is used to explore the nodes level by level from the target node until the desired distance K is reached.

Parent Mapping (mapParent)
This helper function maps each node to its parent for backward traversal:
Traverse the tree recursively.
Record parent relationships for each child node.

Initialize a queue for BFS starting at the target node.
Maintain a visited map to avoid revisiting nodes.

Traverse nodes level by level.
Explore left, right, and parent nodes if they haven’t been visited.
Stop traversal when currLevel == k.

Collect all remaining nodes in the queue at level K.

Time Complexity: O(N) — Traversal of all nodes to map parents and BFS traversal to find nodes at distance K.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void mapParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parentMap)
    {
        if(!root)
          return;
        if(root->left)
        {
            parentMap[root->left] = root;
            mapParent(root->left,parentMap);
        }  
        if(root->right)
        {
            parentMap[root->right] = root;
            mapParent(root->right,parentMap);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parentMap;
        parentMap[root] = nullptr;
        mapParent(root,parentMap);
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target] = true;
        int currLevel = 0;
        while(!q.empty())
        {
            int size = q.size();//ans node should pe present in queue itself
            if(currLevel == k)
              break;
            currLevel++;
            //Traverse over all node at the curr Level
            for(int i=0;i<size;i++)
            {
                auto front = q.front();
                q.pop();
                if(front->left && visited.find(front->left) == visited.end())
                {
                    q.push(front->left);//front has its left child and not visited yet
                    visited[front->left] = true;

                }
                if(front->right && visited.find(front->right) == visited.end())
                {
                    q.push(front->right);//front has its left child and not visited yet
                    visited[front->right] = true;
                }
                auto parentNodeOfParent = parentMap[front];
                if(parentNodeOfParent && visited.find(parentNodeOfParent) == visited.end())
                {
                    q.push(parentNodeOfParent);
                    visited[parentNodeOfParent] = true;
                }
            }  
        }
        vector<int>ans;
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            ans.push_back(front->val);
        }
        return ans;
    }
};