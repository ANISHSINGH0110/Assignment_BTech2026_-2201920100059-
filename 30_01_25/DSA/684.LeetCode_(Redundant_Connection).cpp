/*
Approach

This problem involves identifying an edge in an undirected graph that creates a cycle when added. 
The solution uses the Disjoint Set Union (DSU) (also known as Union-Find) data structure for efficient cycle detection.

Key Concepts:
Union-Find Data Structure:

Maintains a set of disjoint subsets, supporting operations to find the set representative (find) and merge sets (union).
Helps efficiently detect cycles in graphs.
Path Compression:

Optimizes the find() function by directly linking nodes to their root representative.
Redundant Edge Detection:

An edge is redundant if it connects two nodes already in the same set (cycle detected).

p represents the parent of each node. The vector is initialized to a size large enough (1010 in this case) to cover possible nodes.

If p[x] is not its own parent, recursively find the root representative and perform path compression by assigning p[x] to the root.

Iterate through each edge:
If the endpoints a and b share the same root (find(a) == find(b)), a cycle is detected, and the edge is returned.
Otherwise, merge the sets (p[find(a)] = find(b)).

Return an empty vector if no redundant edge is found (though it's guaranteed by the problem that one exists).

Time Complexity: O(N⋅α(N)) — where 
N is the number of edges and 
α is the inverse Ackermann function (nearly constant).
*/


class Solution {
public:
    vector<int> p;
    int find(int x) {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        p.resize(1010);
        for (int i = 0; i < p.size(); ++i)
          p[i] = i;
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            if (find(a) == find(b)) return e;
            p[find(a)] = find(b);
        }
        return {};
    }
    
};