class Solution:
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        freq = defaultdict(int)
        n = len(s)

        for i in range(n - minSize + 1):
            substr = s[i:i + minSize]
            if len(set(substr)) <= maxLetters:
                freq[substr] += 1

        return max(freq.values(), default=0)
