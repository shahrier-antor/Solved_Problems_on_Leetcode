from collections import defaultdict

class Solution:
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        freq = defaultdict(int)
        n = len(s)

        for size in range(minSize, maxSize + 1):
            for i in range(n - size + 1):
                substr = s[i:i + size]
                if len(set(substr)) <= maxLetters:
                    freq[substr] += 1

        return max(freq.values(), default=0)
