class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left = 0
        right = len(numbers)-1

        while(left<=right):
            sum = numbers[left] + numbers[right]
            if sum == target:
                return [left+1, right+1]
            else: 
                mid = (right - left)//2
                if numbers[left] + numbers[mid]<target:
                    left = mid
                else:
                    right = mid

        