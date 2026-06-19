class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int high = matrix.size() - 1;
        int low = 0;
        int target_row = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int size = matrix[mid].size();
            if (matrix[mid][0] > target) {
                high = mid - 1;
            }
            else if (matrix[mid][size - 1] < target) {
                low = mid + 1;
            }
            else {
                target_row = mid;
                break;
            }
        }
        if (target_row == -1) {
            return false;
        }
        else {
            high = matrix[target_row].size() - 1;
            low = 0;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                int mid_value = matrix[target_row][mid];
                if (mid_value == target) {
                    return true;
                }
                else if (mid_value < target) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
            return false;
        }
    }
};
