#include <iostream>
#include <vector>

using namespace std;

void cw_spiral_print(vector<vector<int>> &matrix) {
    // assuming matrix is always valid
    int top = 0, left = 0;
    int bottom = matrix.size() - 1, right = matrix[0].size() - 1;
    int direction = 0;  // 0 = right, 1 = down, 2 = left, 3 = up

    while (top <= bottom && left <= right) {
        if (direction == 0) {
            for (int i = left; i <= right; i++) {
                cout << matrix[top][i] << " ";
            }
            top++;
        }
        if (direction == 1) {
            for (int i = top; i <= bottom; i++) {
                cout << matrix[i][right] << " ";
            }
            right--;
        }
        if (direction == 2) {
            for (int i = right; i >= left; i--) {
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }
        if (direction == 3) {
            for (int i = bottom; i >= top; i--) {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
        direction = (direction + 1) % 4;
    }
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3, 4, 5},
                                  {6, 7, 8, 9, 10},
                                  {11, 12, 13, 14, 15},
                                  {16, 17, 18, 19, 20}};
    cw_spiral_print(matrix);

    return 0;
}