class Solution:
    def numberOfPoints(self, nums: List[List[int]]) -> int:
        ans = 0
        range_tracker = [0]*102
        for num in nums:
            range_tracker[num[0]]+=1
            range_tracker[num[1]+1]-=1
        sum = 0
        for i in range(len(range_tracker)):
            sum+=range_tracker[i]
            if sum>0:
                ans+=1
        return ans 