class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        seen = {}
        result = 0
        l,r = 0,0
        while r < len(s):
            if s[r] in seen:
                l = max(l, seen[s[r]] + 1)
            seen[s[r]] = r
            result = max(result, r - l + 1)
            r += 1
        return result