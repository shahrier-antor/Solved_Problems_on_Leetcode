class Solution:
    def numSubarraysWithSum(self, nums: List[int], goal: int) -> int:
        left = 0
        right = 0
        hashMap = defaultdict(int)
        hashMap[0]=1
        prefixSum = 0
        ans = 0
        k = goal
        while(right<len(nums)):
            prefixSum += nums[right]
            right +=1
            if prefixSum-k>=0:
                ans+=hashMap[prefixSum-k]
            hashMap[prefixSum]+=1
        return ans
