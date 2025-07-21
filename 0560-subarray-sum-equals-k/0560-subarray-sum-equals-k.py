
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        count = 0
        cum_sum = 0
        prefix_map = defaultdict(int)
        prefix_map[0] = 1  # Base case: sum zero before starting

        for num in nums:
            cum_sum += num
            count += prefix_map[cum_sum - k]
            prefix_map[cum_sum] += 1

        return count
