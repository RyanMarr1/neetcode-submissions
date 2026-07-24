class Solution:
    def maxArea(self, heights: List[int]) -> int:
        maxA = 0
        l, r = 0, len(heights) - 1
        while (l < r):
            leftHeight, rightHeight = heights[l], heights[r]
            area = min(leftHeight, rightHeight) * (r - l)
            maxA = max(maxA, area)
            if leftHeight < rightHeight:
                l += 1
            else:
                r -= 1
        return maxA
        