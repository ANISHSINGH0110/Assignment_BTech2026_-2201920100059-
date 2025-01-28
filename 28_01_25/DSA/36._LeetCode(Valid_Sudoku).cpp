//Approach

/*
The problem requires checking whether a partially filled 9x9 Sudoku board is valid. A valid Sudoku board must satisfy the following rules:

Each row must contain unique digits from 1 to 9 (no duplicates).
Each column must contain unique digits from 1 to 9.
Each of the nine 3x3 sub-boxes must also contain unique digits from 1 to 9.

Use three vectors of hash sets to keep track of already seen digits:
rows[i]: Tracks numbers seen in the i-th row.
cols[j]: Tracks numbers seen in the j-th column.
boxes[boxIndex]: Tracks numbers seen in the boxIndex-th 3x3 sub-grid.

Loop through each cell in the board.
For each filled cell (i, j) with digit d:
Compute the index of the corresponding 3x3 box using the formula:
boxIndex = (i / 3) * 3 + j / 3
Check if d already exists in the corresponding row, column, or sub-grid:
If any set contains d, return false as it violates the Sudoku rule.
Otherwise, insert d into the respective row, column, and box sets.

Ignore cells containing . since they are unfilled.

If no duplicates are found, return true indicating the board is valid.

Time Complexity: O(9^2 ) = O(1)

*/





class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        // Use hash sets to track seen numbers
        vector<set<char>> rows(n), cols(n), boxes(n);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                char digit = board[i][j];
                
                // Skip empty cells
                if (digit == '.') continue;
                
                // Compute box index
                int boxIndex = (i / 3) * 3 + j / 3;
                
                // Check for duplicates
                if (rows[i].count(digit) || cols[j].count(digit) || boxes[boxIndex].count(digit))
                    return false;

                // Add digit to respective row, column, and box sets
                rows[i].insert(digit);
                cols[j].insert(digit);
                boxes[boxIndex].insert(digit);
            }
        }
        return true;
    }
};
