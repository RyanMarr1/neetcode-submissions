class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit = 0
        left, right = 0,0
        for _ in range(1, len(prices)):
            right += 1
            lP = prices[left]
            rP = prices[right]
            if lP > rP:
                left = right
            else:
                profit = max(profit, rP - lP)
        return profit
        