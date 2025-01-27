/*
We are given:

numCourses: The total number of courses.
prerequisites: A list of direct prerequisite pairs [u, v] meaning course u is a prerequisite of course v.
queries: A list of queries [u, v], asking whether u is a prerequisite for v.
Our goal is to return a boolean array where each query result is true if course u is a prerequisite of v, otherwise false.

The problem is solved using the Floyd-Warshall Algorithm, which efficiently computes the transitive closure of a graph by checking indirect prerequisites.

Create a numCourses x numCourses matrix isPrerequisite initialized with false values.
Mark direct prerequisite relationships based on the prerequisites list.

Use three nested loops to update the matrix using the formula:
isPrerequisite[i][j]=isPrerequisite[i][j] OR (isPrerequisite[i][k] AND isPrerequisite[k][j])
This step ensures that if i → k and k → j, then i → j.

For each query [u, v], check if isPrerequisite[u][v] is true and store the result.

The Floyd-Warshall algorithm runs in O(n^3), where n = numCourses.
*/




class Solution {
 public:
  vector<bool> checkIfPrerequisite(int numCourses,
                                   vector<vector<int>>& prerequisites,
                                   vector<vector<int>>& queries) {
    vector<bool> ans;
    // isPrerequisite[i][j] := true if course i is a prerequisite of course j
    vector<vector<bool>> isPrerequisite(numCourses, vector<bool>(numCourses));

    for (const vector<int>& prerequisite : prerequisites) {
      const int u = prerequisite[0];
      const int v = prerequisite[1];
      isPrerequisite[u][v] = true;
    }

    for (int k = 0; k < numCourses; ++k)
      for (int i = 0; i < numCourses; ++i)
        for (int j = 0; j < numCourses; ++j)
          isPrerequisite[i][j] = isPrerequisite[i][j] ||
                                 (isPrerequisite[i][k] && isPrerequisite[k][j]);

    for (const vector<int>& query : queries) {
      const int u = query[0];
      const int v = query[1];
      ans.push_back(isPrerequisite[u][v]);
    }

    return ans;
  }
};