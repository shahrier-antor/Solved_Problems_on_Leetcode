from collections import defaultdict

class Solution:
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        n = len(s)
        freq = defaultdict(int)

        for size in range(minSize, maxSize + 1):
            left = 0
            right = 0

            while right < n:
                # Expand window
                window_len = right - left + 1

                if window_len < size:
                    right += 1
                elif window_len == size:
                    substr = s[left:right + 1]
                    if len(set(substr)) <= maxLetters:
                        freq[substr] += 1
                    left += 1
                    right += 1
                else:
                    # if window got too big, move left forward
                    left += 1

        return max(freq.values(), default=0)
