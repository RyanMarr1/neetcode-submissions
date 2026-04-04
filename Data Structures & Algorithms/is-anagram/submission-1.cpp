#include <unordered_map>
#include <string>
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map_s;
        unordered_map<char, int> map_t;
        if (s.size() != t.size()) {
            return false;
        }
        for (int i = 0; i < s.size(); i++) {

            map_s[s[i]]++;
            map_t[t[i]]++;
        }
        if (map_s == map_t){
            return true;
        }
        else {
            return false;
        }
    }
};
