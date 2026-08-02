class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));

        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;
        int num = 1;

        while (top <= bottom && left <= right) {

            // Left -> Right
            for (int j = left; j <= right; j++)
                matrix[top][j] = num++;
            top++;

            // Top -> Bottom
            for (int i = top; i <= bottom; i++)
                matrix[i][right] = num++;
            right--;

            // Right -> Left
            if (top <= bottom) {
                for (int j = right; j >= left; j--)
                    matrix[bottom][j] = num++;
                bottom--;
            }

            // Bottom -> Top
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    matrix[i][left] = num++;
                left++;
            }
        }

        return matrix;
    }
};