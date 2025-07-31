class Solution:
    def numberOfPoints(self, nums: List[List[int]]) -> int:
        hashMap = defaultdict(int)
        
        for i in range (0, len(nums)):
            for j in range (nums[i][0], nums[i][1]+1):
                if j not in hashMap:
                    hashMap[j] = 1
        
        return len(hashMap)