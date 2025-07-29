class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        prefixSum = 0
        ans = 0
        hashMap = defaultdict(int)
        hashMap[0]+=1
        for num in nums:
            prefixSum+=num
            remain = (prefixSum%k+k)%k
            ans += hashMap[remain]
            hashMap[remain]+=1
        return ans