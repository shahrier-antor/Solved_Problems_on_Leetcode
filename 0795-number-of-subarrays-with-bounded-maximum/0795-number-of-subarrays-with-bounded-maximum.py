
class Solution:
    def numSubarrayBoundedMax(self, nums: List[int], left: int, right: int) -> int:
        ans = 0
        low = 0          # 1 past the last index where nums[i] > right
        add = 0          # number of valid subarrays ending at previous index

        for high, x in enumerate(nums):
            if x > right:
                low = high + 1   # window is broken
                add = 0          # nothing valid ends here
            elif x >= left:       # x is a "good" max, resets add
                add = high - low + 1
                ans += add
            else:                 # x < left, extend previous valid runs
                ans += add
        return ans
