#include <unordered_map>
#include <map>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> nums_map;
        vector<vector<int>> ordered_nums (nums.size() + 1);
        vector<int> result;
        for (auto num : nums) {
            nums_map[num]++;
        }
        for (auto [key, value] : nums_map) {
            ordered_nums[value].push_back(key);
        }
        for (int i = ordered_nums.size() - 1; i >= 0 && k > 0; i--) {
            if (!ordered_nums[i].empty()) {
                for (int num : ordered_nums[i]) {
                    if (k > 0) {
                        result.push_back(num);
                        k--;
                    }
                }
            }
        }
        return result;
    }
};