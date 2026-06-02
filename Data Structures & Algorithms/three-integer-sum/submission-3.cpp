class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int i = 0;
        while (i < nums.size() - 2) {
            int left = i + 1;
            int right = nums.size() - 1;
            int target = -nums[i];
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    right--;
                    left++;
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
                else if (sum > target) {
                    right--;
                }
                else {
                    left++;
                }
            }
            i++;
            while (i < nums.size() - 2 && nums[i] == nums[i - 1]) {
                i++;
            }
        }
        return result;
    }
};