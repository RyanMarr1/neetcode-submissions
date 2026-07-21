class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t) : return False
        s_dict = {}
        t_dict = {}
        for sletter, tletter in zip(s,t):
            s_dict[sletter] = s_dict.get(sletter, 0) + 1
            t_dict[tletter] = t_dict.get(tletter, 0) + 1
        if s_dict == t_dict: return True
        else: return False