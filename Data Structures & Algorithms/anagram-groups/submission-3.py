class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        sorted_entries = defaultdict(list)
        for s in strs:
            aToZ = [0] * 26
            for c in s:
                aToZ[ord(c) - ord('a')] += 1
            sorted_entries[tuple(aToZ)].append(s)
        return list(sorted_entries.values())

        


        