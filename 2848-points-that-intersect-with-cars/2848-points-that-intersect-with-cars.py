class Solution:
    def numberOfPoints(self, nums: List[List[int]]) -> int:
        points = set()
        for num in nums:
            for i in range(num[0], num[1] + 1):
                points.add(i)
        return len(points)
