#include <vector>
#include <unordered_map>
#include <algorithm>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> word_list;
        unordered_map<string, vector<string>> ana_list;
        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            ana_list[temp].push_back(strs[i]);
        }
        for (auto it = ana_list.begin(); it != ana_list.end(); it++) {
            word_list.push_back(it->second);
        }
        return word_list;
    }
};
