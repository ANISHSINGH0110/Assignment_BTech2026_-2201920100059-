/*
limit: An integer that specifies the upper bound on query operations (unused in the solution).
queries: A vector of pairs, where each pair [ball, color] represents an operation to assign a color to a specific ball.
unordered_map<int, int> ballToColor: Stores the current color assigned to each ball.
Key: Ball number
Value: Assigned color
unordered_map<int, int> colorCount: Tracks the count of balls assigned to each color.
Key: Color
Value: Number of balls with that color
The loop processes each query, handling color assignments and updates.
Check if the ball is already assigned a color (prevColor).
If found, decrement the count of prevColor in colorCount.
If the count of the previous color becomes zero, remove it from colorCount.
Assign the new color to the ball.
Increment the count of the assigned color.
Append the number of unique colors (colorCount.size()) to ans.
The function returns ans, a vector containing the number of distinct colors after each query.

Time Complexity: O(n), where n is the number of queries, because each query operation (insertion, update, and deletion) takes O(1) time.
*/
class Solution {
 public:
  vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    vector<int> ans;
    unordered_map<int, int> ballToColor;
    unordered_map<int, int> colorCount;

    for ( vector<int>& query : queries) {
      int ball = query[0];
      int color = query[1];
      if (auto it = ballToColor.find(ball); it != ballToColor.cend()) {
        int prevColor = it->second;
        if (--colorCount[prevColor] == 0)
          colorCount.erase(prevColor);
      }
      ballToColor[ball] = color;
      ++colorCount[color];
      ans.push_back(colorCount.size());
    }

    return ans;
  }
};