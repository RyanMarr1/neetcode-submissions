#include <array>
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        array<int, 26> char_count{};
        for (int i = 0; i < s.size(); i++) {
            char_count[s[i] - 'a']++;
            char_count[t[i] - 'a']--;
        }
        for (int x : char_count) {
            if (x != 0) {
                return false;
            }
        }
        return true;
    }
};
