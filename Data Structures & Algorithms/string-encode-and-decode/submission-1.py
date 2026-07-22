class Solution:

    def encode(self, strs: List[str]) -> str:
        result = ""
        for s in strs:
            result += str(len(s)) + "#" + s
        print(result)
        return result

    def decode(self, s: str) -> List[str]:
        i = 0
        result = []
        while i < len(s):
            str_len = ""
            while s[i] != "#":
                str_len += s[i]
                i += 1
            str_len = int(str_len)
            word = s[i + 1:i + 1 + str_len]
            i += str_len + 1
            result.append(word)
        return result
            
        
