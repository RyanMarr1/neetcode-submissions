class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        numDict = {}
        for num in nums:
            if num in numDict:
                return True
            numDict[num] = 1
        return False
        
        