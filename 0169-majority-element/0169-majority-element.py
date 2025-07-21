class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        hashMap = {}
        for num in nums:
            if num not in hashMap:
                hashMap[num] = 0
            hashMap[num]+=1
        for key, val in hashMap.items():
            if val > len(nums)/2:
                return key