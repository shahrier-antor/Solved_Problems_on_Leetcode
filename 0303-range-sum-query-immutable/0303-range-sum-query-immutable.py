class NumArray:

    def __init__(self, nums: List[int]):
        # Compute the prefix sum array
        self.preSum = nums
        for i in range(1, len(self.preSum)):
            self.preSum[i] += self.preSum[i - 1]

    def sumRange(self, left: int, right: int) -> int:
        if left == 0:
            return self.preSum[right]
        return self.preSum[right] - self.preSum[left - 1]
        


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)