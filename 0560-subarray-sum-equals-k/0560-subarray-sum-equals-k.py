
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        ans = 0
        prefixSum = 0
        hashMap = defaultdict(int)
        for num in nums:
            prefixSum+=num
            if prefixSum == k:
                ans+=1
            hashMap[prefixSum]+=1
            ans+= hashMap[prefixSum-k]
        return ans
