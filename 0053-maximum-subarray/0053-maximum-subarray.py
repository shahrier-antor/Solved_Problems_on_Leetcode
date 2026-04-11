class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        prefix_sum, ans = 0, - float("inf")

        for num in nums:
            if prefix_sum < 0:
                prefix_sum = 0
            current_sum = prefix_sum + num
            prefix_sum = current_sum
            ans = max(current_sum, ans)

        return ans