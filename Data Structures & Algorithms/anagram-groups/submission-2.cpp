#include <vector>
#include <unordered_map>
#include <algorithm>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> ana_list;
        for (const auto &s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            ana_list[temp].push_back(s);
        }
        for (auto &[key, value] : ana_list) {
            result.push_back(move(value));
        }
        return result;
    }
};
