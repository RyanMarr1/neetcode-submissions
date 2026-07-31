class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        charCount = defaultdict(int)
        l = 0
        longest = 0
        for r in range(len(s)):
            window_size = r - l + 1
            charCount[s[r]] += 1
            if window_size - max(charCount.values()) <= k:
                longest = max(longest, window_size)
            else:
                charCount[s[l]] -= 1
                l += 1
        return longest
