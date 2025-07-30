class Solution:
    def atMostK(self, nums: List[int], k: int) ->int:
        count = 0
        left = 0
        right = 0
        oddCount = 0
        while(right<len(nums)):
            if nums[right] % 2 == 1:
                oddCount+=1
            right+=1
            while oddCount>k:
                if nums[left]%2 == 1:
                        oddCount -=1
                left+=1
            count+= right-left+1
        return count
    
    def numberOfSubarrays(self, nums: List[int], k: int) -> int:
        return self.atMostK(nums, k) - self.atMostK(nums, k-1)