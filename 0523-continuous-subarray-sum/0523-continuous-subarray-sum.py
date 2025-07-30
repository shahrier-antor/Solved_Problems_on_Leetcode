class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        hashMap = defaultdict(int)
        prefixSum = 0
        hashMap[0] = -1
        for idx, num in enumerate(nums):
            prefixSum+=num
            remain = prefixSum%k
            if remain in hashMap:
                if idx - hashMap[remain] > 1:
                    return True
            else:
                hashMap[remain] = idx
        
        return False

