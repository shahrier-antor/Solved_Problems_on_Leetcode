class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
         
        n = len(s)
        left = right = 0
        freq = {}
        longest = 0

        while (right<n):
            if s[right] not in freq:
                freq[s[right]] = 1
            else:
                freq[s[right]]+=1
            if freq[s[right]]>1:
                while (freq[s[right]]>1):
                    freq[s[left]]-=1
                    left+=1
            longest = max (longest, right-left+1)
            right += 1
        return longest

