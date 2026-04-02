class Solution:
    def trap(self, height: List[int]) -> int:
        left = 0
        right = len(height) - 1
        maxLeft = height[left]
        maxRight = height[right]

        trapped = 0
       
        while(left<right):
            if(maxLeft<maxRight):
                trapped+= maxLeft - height[left]
                left+=1
                maxLeft = max(maxLeft, height[left])
            else: 
                trapped+=maxRight - height[right]
                right-=1
                maxRight = max(maxRight, height[right])

        return trapped


    
     