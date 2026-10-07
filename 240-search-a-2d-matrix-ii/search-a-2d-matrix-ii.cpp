class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int row = 0;
        int col = n - 1; // Top-right corner
        
        while (row < m && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] > target) {
                col--; // Target is smaller, eliminate current column
            } else {
                row++; // Target is larger, eliminate current row
            }
        }
        
        return false;
    }
};