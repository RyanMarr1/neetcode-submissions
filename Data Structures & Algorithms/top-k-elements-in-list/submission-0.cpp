#include <unordered_map>
#include <map>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> nums_map;
        map<int, vector<int>> ordered_nums;
        vector<int> result;
        for (auto num : nums) {
            nums_map[num]++;
        }
        for (auto [key, value] : nums_map) {
            ordered_nums[value].push_back(key);
        }
        while (k > 0) {
            auto it = prev(ordered_nums.end());
            vector<int> temp = it->second;
            result.insert(result.end(), temp.begin(), temp.end());
            ordered_nums.erase(it);
            k -= temp.size();
        }
        return result;
    }
};
