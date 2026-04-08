class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        ans = 1000000
        left = 0
        current = 0
        for right in range (len(nums)):
            current += nums[right]
            while(current >= target):
                ans = min(ans, right-left+1)
                current -= nums[left]
                left += 1            
        
        return 0 if ans == 1000000 else ans

