#include <unordered_set>
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> stored_nums;
        for (int i = 0; i < nums.size(); i++) {
            if (stored_nums.find(nums[i]) == stored_nums.end()) {
                stored_nums.insert(nums[i]);
            }
            else {
                return true;
            }
        }
        return false;
    }
};