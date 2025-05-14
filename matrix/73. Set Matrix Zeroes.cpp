class Solution {
    public:
       
        void setZeroes(vector<vector<int>>& matrix) {
            int m = matrix.size();
            int n = matrix[0].size();
    
            bool firstRow = false, firstCol = false;
    
            // Determine if the first row or first column should be zero
            for (int i = 0; i < m; ++i) {
                if (matrix[i][0] == 0) {
                    firstCol = true;
                    break;
                }
            }
    
            for (int j = 0; j < n; ++j) {
                if (matrix[0][j] == 0) {
                    firstRow = true;
                    break;
                }
            }
    
            // Use the first row and column to mark zero rows and columns
            for (int i = 1; i < m; ++i) {
                for (int j = 1; j < n; ++j) {
                    if (matrix[i][j] == 0) {
                        matrix[i][0] = 0;
                        matrix[0][j] = 0;
                    }
                }
            }
    
            // Zero out the marked rows and columns
            for (int i = 1; i < m; ++i) {
                if (matrix[i][0] == 0) {
                    for (int j = 1; j < n; ++j) {
                        matrix[i][j] = 0;
                    }
                }
            }
    
            for (int j = 1; j < n; ++j) {
                if (matrix[0][j] == 0) {
                    for (int i = 1; i < m; ++i) {
                        matrix[i][j] = 0;
                    }
                }
            }
    
            // Finally, handle the first row and column
            if (firstCol) {
                for (int i = 0; i < m; ++i) {
                    matrix[i][0] = 0;
                }
            }
    
            if (firstRow) {
                for (int j = 0; j < n; ++j) {
                    matrix[0][j] = 0;
                }
            }
        }
    };