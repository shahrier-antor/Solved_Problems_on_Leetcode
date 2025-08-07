class Solution:
    def numSubarrayBoundedMax(self, nums: List[int], left: int, right: int) -> int:
        low, high = 0,0
        ans = 0
        max_ele = -1

        while(high<len(nums)):
            max_ele = max(max_ele, nums[high])
            if left<=max_ele<=right:
                if max_ele == nums[high]:
                    ans+= (high-low+1)
                else: ans+=1
            else:
                high +=1
                low = high
                max_ele = -1
                continue
            high+=1
        return ans 