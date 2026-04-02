class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        s = {}
        res = []
        for i,n in enumerate(numbers):
            compli = target - n
            if compli not in s:
                s[n] = i
            else:
                res.append(s[compli] + 1)
                res.append(i + 1)
                return res
        return