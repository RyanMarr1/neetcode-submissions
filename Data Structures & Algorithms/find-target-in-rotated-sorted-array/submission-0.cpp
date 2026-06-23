class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (mid > 0) {
                if (nums[mid] < nums[mid - 1]) {
                    break;
                }
            }
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        if (mid == 0) {
            low = 0;
            high = nums.size() - 1;
        }
        else if (target >= nums[0]) {
            low = 0;
            high = mid - 1;
        }
        else {
            low = mid;
            high = nums.size() - 1;
        }
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return -1;
    }
};
