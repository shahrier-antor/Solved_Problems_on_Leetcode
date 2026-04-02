from collections import Counter

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        left = 0
        freq_s1 = Counter(s1)
        freq_s2 = {}

        for right in range(len(s2)):
            # Add current character
            freq_s2[s2[right]] = freq_s2.get(s2[right], 0) + 1

            # Shrink window if too big
            if right - left + 1 > len(s1):
                freq_s2[s2[left]] -= 1
                if freq_s2[s2[left]] == 0:
                    del freq_s2[s2[left]]
                left += 1

            # Check when window size matches
            if right - left + 1 == len(s1):
                if freq_s1 == freq_s2:
                    return True

        return False