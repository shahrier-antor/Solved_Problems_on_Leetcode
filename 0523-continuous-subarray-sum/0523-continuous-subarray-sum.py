class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        hashMap = defaultdict(list)
        prefixSum = 0
        hashMap[0].append(-1)
        for i in range(0, len(nums)):
            prefixSum+=nums[i]
            remain = prefixSum%k
            if remain in hashMap:
                for idx in hashMap[remain]:
                    if i - idx > 1:
                        return True
            hashMap[remain].append(i)
        
        return False

