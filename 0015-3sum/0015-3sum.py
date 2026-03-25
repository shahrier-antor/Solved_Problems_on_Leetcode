class Solution:
    def threeSum(self, nums):
        nums.sort()
        result = []

        for i in range(len(nums)):
            # skip duplicate i
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            left = i + 1
            right = len(nums) - 1

            while left < right:
                s = nums[i] + nums[left] + nums[right]

                if s == 0:
                    result.append([nums[i], nums[left], nums[right]])
                    left += 1
                    right -= 1

                elif s < 0:
                    left += 1
                else:
                    right -= 1

        # remove duplicates at the end
        unique = []
        for triplet in result:
            if triplet not in unique:
                unique.append(triplet)

        return unique