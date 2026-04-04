#include <unordered_map>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> stored_nums;
        for (int i = 0; i < nums.size(); i++) {
            if (stored_nums.find(nums[i]) == stored_nums.end()) {
                stored_nums[nums[i]] = 1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};