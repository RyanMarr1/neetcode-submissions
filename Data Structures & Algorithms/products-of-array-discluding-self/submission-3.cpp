class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        bool zero_flag = false;
        bool all_zero_flag = true;
        vector<int> result (nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0 && !zero_flag) {
                zero_flag = true;
            }
            else {
                all_zero_flag = false;
                product *= nums[i];
            }
        }
        for (int i = 0; i < result.size(); i++) {
            if (all_zero_flag) {
                result[i] = 0;
            }
            else if (zero_flag && nums[i] == 0) {
                result[i] = product;
            }
            else if (zero_flag && nums[i] != 0) {
                result[i] = 0;
            }
            else {
                result[i] = product / nums[i];
            }
        }
        return result;
    }
};