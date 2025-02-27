class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        while part in s:
            start_idx = s.find(part)

            s = s[:start_idx] + s[start_idx+len(part):]
        return s