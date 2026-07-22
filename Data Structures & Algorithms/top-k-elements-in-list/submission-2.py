class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        numCount = defaultdict(int)

        for num in nums:
            numCount[num] += 1

        freqBuckets = [[] for i in range(len(nums) + 1)]

        for key, value in numCount.items():
            freqBuckets[value].append(key)
        
        result = []
        for values in reversed(freqBuckets):
            for value in values:
                result.append(value)
                if len(result) == k:
                    return result



