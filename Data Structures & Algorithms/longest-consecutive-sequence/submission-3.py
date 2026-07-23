class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        seenSet = set(nums)
        result = 0
        for seen in seenSet:
            if not (seen - 1) in seenSet:
                longest = 1
                while (seen + longest) in seenSet:
                    longest += 1
                result = max(longest, result)
        return result