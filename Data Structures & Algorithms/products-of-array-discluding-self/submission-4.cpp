class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result (nums.size());
        int mult = 1;
        result[0] = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            result[i + 1] = result[i] * nums[i];
        }
        for (int i = nums.size() - 1; i > -1; i--) {
            result[i] *= mult;
            mult *= nums[i];
        }
        return result;
    }
};
