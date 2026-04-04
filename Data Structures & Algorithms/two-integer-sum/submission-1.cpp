#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nums_map;
        for (int i = 0; i < nums.size(); i++) {
            int goal = target - nums[i];
            auto it = nums_map.find(goal);

            if (it == nums_map.end()) {
                nums_map[nums[i]] = i;
            }
            else {
                return {nums_map[it->first], i};
            }
        }
        return {};
    }
};
