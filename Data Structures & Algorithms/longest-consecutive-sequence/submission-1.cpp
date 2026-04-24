class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> logged_nums;
        for (auto &num : nums) {
            logged_nums.insert(num);
        }
        int result = 0;
        int count = 1;
        auto it = logged_nums.begin();
        int curr_num = *it;
        for (; it != logged_nums.end(); it++) {
            if (it == logged_nums.begin()) {
                result++;
                continue;
            }
            int diff = *it - curr_num;
            curr_num = *it;
            if (diff == 1) {
                count++;
                if (count > result) {
                    result = count;
                }
            }
            else {
                count = 1;
            }
        }
        return result;
    }
};
