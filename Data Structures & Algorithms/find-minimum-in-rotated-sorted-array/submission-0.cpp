class Solution {
public:
    int findMin(vector<int> &nums) {
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
        return nums[mid];
    }
};
