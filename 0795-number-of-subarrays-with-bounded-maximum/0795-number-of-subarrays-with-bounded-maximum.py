
class Solution:
    def maxK(self, nums:List[int], k:int):
        left, right = 0,0
        maxele = -1
        ans = 0
        while(right<len(nums)):
            maxele = max(maxele, nums[right])
            if maxele>k:
                maxele=-1
                left = right+1
            ans+= (right-left+1)
            right+=1
        return ans

    def numSubarrayBoundedMax(self, nums: List[int], left: int, right: int) -> int:
        print (self.maxK(nums, right), self.maxK(nums,left-1))
        return self.maxK(nums, right) - self.maxK(nums,left-1)
